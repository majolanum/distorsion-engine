#pragma once
#include <SDL.h>
#include <vector>

#include "Lib2D/Window.h"
#include "Lib2D/InputManager.h"
#include "Distortion_engine/SceneManager.h"
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

	bool* run;

	void GetEvent();

public:
	bool InitApplication();
	void RunApplication(bool* run);
	void EndApplication();

	template<typename T>
	void AddGame(std::string gameName);
	
	void ChangeGame(std::string gameName);

};

template<typename T>
inline void Application::AddGame(std::string gameName)
{
	T* newGame = new T(gameName);
	m_AllGame.push_back(newGame);
}
