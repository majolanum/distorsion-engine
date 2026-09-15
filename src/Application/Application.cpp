#include "Application.h"

Application* Application::instance = nullptr;

Application* Application::Get()
{
	if (instance == nullptr)
		instance = new Application;
	return instance;
}

bool* Application::InitApplication()
{
	try
	{
		m_MainWindow = new Window();
		m_MainWindow->OpenWindow();

		m_ImputeManager = InputManager::Get();

		m_ActualGame = nullptr;

		m_FPSTimer = new Timer();
		run = true;
	}
	catch (std::exception ex)
	{
		run = false;
	}
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
		else
			m_ActualGame->DrawActualGame(m_MainWindow);
	}
	else
		ChooseGame();

	m_MainWindow->Present();

	DeltaTime = m_FPSTimer->EndTimer();

	int diff = TARGET_ELAPSED - DeltaTime;
	if (diff > 0)
	{
		SDL_Delay(diff);
		DeltaTime = TARGET_ELAPSED;
	}
	DeltaTime::SetDeltaTime(DeltaTime);

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
		run = false;
		return;
	}
}

void Application::ChooseGame()
{
	int choose = 0;
	int i = 0;
	system("cls");
	for (Game* g : m_AllGame)
	{
		std::cout << g->m_Name << " = " << i << std::endl;
	}
	std::cin >> choose;
	if (choose != -1)
	{
		ChangeGame(m_AllGame[choose]->m_Name);
	}
	else
		run = false;
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
