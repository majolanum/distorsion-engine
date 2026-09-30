#pragma once
#include <SDL3/SDL.h>
#include <vector>

#include "Lib2D/Window.h"
#include "Distortion_engine/InputManager.h"
#include "Distortion_engine/Timer.h"
#include "Distortion_engine/Game.h"

#define TARGET_FPS 60
#define TARGET_ELAPSED 1000/TARGET_FPS

class Application
{
private:
	Window* m_MainWindow;
	InputManager* m_ImputeManager;
	SDL_Event event;

	std::vector<Game*> m_AllGame;
	Game* m_ActualGame;

	float DeltaTime = 0, TotalElapsed = 0;
	int FramCount = 0;
	Timer* m_FPSTimer;

	std::string m_SelecteGame = "Select_Game";

	bool run = false;

	Application() {}
	static Application* instance;

	void GetEvent();

public:
	static Application* Get();

	bool* InitApplication();
	void RunApplication();
	void EndApplication();

	template<typename T>
	void AddGame(std::string gameName, std::string gameIconLink);
	
	void ChooseGame();
	void ChangeGame(std::string gameName);
};

template<typename T>
inline void Application::AddGame(std::string gameName, std::string gameIconLink)
{
	T* newGame = new T(gameName, gameIconLink);
	m_AllGame.push_back(newGame);
}
