#pragma once
#include <SDL.h>

#include "Lib2D/Window.h"
#include "Distortion_engine/SceneManager.h"
#include "Distortion_engine/TestScene.h"
#include "Distortion_engine/Timer.h"
#include "Lib2D/InputManager.h"

#define TARGET_FPS 60
#define TARGET_ELAPSED 1000/TARGET_FPS

class Application
{
private:
	Window* m_MainWindow;
	InputManager* m_ImputeManager;
	SDL_Event event;

	float DeltaTime = 0, TotalElapsed = 0;
	int FramCount = 0;
	Timer* m_FPSTimer;

	bool* run;

public:
	bool InitApplication();
	void RunApplication(bool* run);
	void EndApplication();

	void GetEvent();

};

