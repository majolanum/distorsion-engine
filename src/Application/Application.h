#pragma once
#include <SDL3/SDL.h>
#include <vector>

#include "Lib2D/Window.h"
#include "Distortion_engine/InputManager.h"
#include "Distortion_engine/Timer.h"
#include "Distortion_engine/Game.h"

constexpr int TARGET_FPS = 60;
constexpr float TARGET_ELAPSED = 1000 / TARGET_FPS;

class Application
{
private:
	Window* m_MainWindow = nullptr;
	InputManager* m_ImputeManager = nullptr;
	SDL_Event event;

	std::vector<Game*> m_AllGame;
	Game* m_ActualGame = nullptr;

	float DeltaTime = 0, TotalElapsed = 0;
	int FramCount = 0;
	Timer* m_FPSTimer = nullptr;

	std::string m_SelecteGame = "Select_Game";

	bool run = false;

	Application() = default;
	static Application* instance;

	void GetEvent();
	bool* InitApplication();
	void RunApplication();
	void DrawApplication();
	void EndApplication();
	
	void ChooseGame();
	void ChangeGame(std::string gameName);

public:
	static Application* Get();

	void LauchApp();

	template<typename T>
	void AddGame(std::string gameName, std::string gameIconLink);

	friend class SelectGame;
};

template<typename T>
inline void Application::AddGame(std::string gameName, std::string gameIconLink)
{
	T* newGame = new T(gameName, gameIconLink);
	m_AllGame.push_back(newGame);
}
