#include "Application.h"
#include "ApplicationInfo.h"
#include "SelectGame.h"
#include "Lib2d/Debug.h"

Application* Application::instance = nullptr;

Application* Application::Get()
{
	if (instance == nullptr)
		instance = new Application;
	return instance;
}

void Application::LauchApp()
{
	InitApplication();
	while (run)
		RunApplication();
	EndApplication();
}

bool* Application::InitApplication()
{
	m_MainWindow = new Window();
	ApplicationInfo::SetWindowSize(m_MainWindow->OpenWindow());

	m_ImputeManager = InputManager::Get();

	m_ActualGame = nullptr;

	m_FPSTimer = new Timer();
	run = true;

	AddGame<SelectGame>(m_SelecteGame, ApplicationInfo::GetTemplateLink());

	return &run;
}

void Application::RunApplication()
{
	m_FPSTimer->StartTimer();
	m_MainWindow->ClearWindow();

	GetEvent();

	if (run == false)
		return;

	if (m_ActualGame != nullptr)
	{
		m_ActualGame->Update(DeltaTime);
		if (!m_ActualGame->IsRuning)
		{
			m_ActualGame->EndGame();
			m_ActualGame = nullptr;
		}
		DrawApplication();
	}
	else
		ChooseGame();

	m_MainWindow->Present();

	DeltaTime = m_FPSTimer->EndTimer();

	float diff = TARGET_ELAPSED - DeltaTime;
	if (diff > 0)
	{
		SDL_Delay(diff);
		DeltaTime = TARGET_ELAPSED;
	}
	ApplicationInfo::SetDeltaTime(DeltaTime);

	TotalElapsed += DeltaTime;
	if (TotalElapsed >= 1000)
	{
		std::cout << "fps : " << FramCount << std::endl;
		TotalElapsed = 0;
		FramCount = 0;
	}
	FramCount++;
}

void Application::DrawApplication()
{
	if (m_ActualGame != nullptr)
	{
		m_ActualGame->DrawActualGame(m_MainWindow);
	}
	Debug::Draw(m_MainWindow->GetRenderer());
}

void Application::EndApplication()
{
	for (Game* g : m_AllGame)
	{
		delete g;
	}
	m_AllGame.clear();
	delete m_MainWindow;
}

void Application::GetEvent()
{
	while (SDL_PollEvent(&event))
	{
		m_ImputeManager->Update(event);
	}
	if (m_ImputeManager->IsKeyDown(Key_echap))
	{
		run = false;
		return;
	}
}

void Application::ChooseGame()
{
	if (m_ActualGame == nullptr)
	{
		ChangeGame(m_SelecteGame);
		if (!dynamic_cast<SelectGame*>(m_ActualGame)->SetAllGame(m_AllGame))
		{
			run = false;
		}
	}
}

void Application::ChangeGame(std::string gameName)
{
	for (Game* g : m_AllGame)
	{
		if (g->m_Name == gameName)
		{
			if (m_ActualGame != nullptr)
				m_ActualGame->EndGame();

			m_ActualGame = g;
			m_ActualGame->Initialize();
		}
	}
}
