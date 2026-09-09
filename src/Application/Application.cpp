#include "Application.h"


bool Application::InitApplication()
{
	try
	{
		m_MainWindow = new Window();
		m_MainWindow->OpenWindow();

		m_ImputeManager = InputManager::Get();
		
		m_ActualGame = nullptr;

		m_FPSTimer = new Timer();
		return true;
	}
	catch (std::exception ex)
	{
		return false;
	}
}

void Application::RunApplication(bool* Run)
{
	run = Run;
	m_FPSTimer->StartTimer();
	m_MainWindow->ClearWindow();

	GetEvent();

	if (*run == false)
		return;
	
	if (m_ActualGame != nullptr)
	{
		m_ActualGame->Update(DeltaTime);
		m_ActualGame->DrawActualGame(m_MainWindow);
	}

	m_MainWindow->Present();

	DeltaTime = m_FPSTimer->EndTimer();

	int diff = TARGET_ELAPSED - DeltaTime;
	if (diff > 0)
	{
		SDL_Delay(diff);
		DeltaTime = TARGET_ELAPSED;
	}

	TotalElapsed += DeltaTime;
	if (TotalElapsed >= 1000)
	{
		std::cout << "fps : " << FramCount << std::endl;
		TotalElapsed = 0;
		FramCount = 0;
	}
	FramCount++;
}

void Application::EndApplication()
{
	for (Game* g : m_AllGame)
	{
		delete g;
	}
	m_AllGame.clear();
}

void Application::GetEvent()
{
	while (SDL_PollEvent(&event))
	{
		m_ImputeManager->Update(event);
	}
	if (m_ImputeManager->IsKeyDown(Key_echap))
	{
		delete m_MainWindow;
		SDL_Quit();
		*run = false;
		return;
	}
}

void Application::ChangeGame(std::string gameName)
{
	for (Game* g : m_AllGame)
	{
		if (g->m_Name == gameName)
		{
			m_ActualGame = g;
			m_ActualGame->Initialize();
		}
	}
}
