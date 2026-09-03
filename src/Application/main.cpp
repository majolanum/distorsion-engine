#include <iostream>
#include <SDL.h>

#include "main.h"
#include "Lib2D/Window.h"
#include "Distortion_engine/SceneManager.h"
#include "Distortion_engine/TestScene.h"
#include "Distortion_engine/Timer.h"

#include "Lib2D/InputManager.h"

#define TARGET_FPS 60
#define TARGET_ELAPSED 1000/TARGET_FPS


int main(int argc, char* argv[])
{
	std::cout << "Hello, World!\n";
	Window* window = new Window();
	window->OpenWindow();
	
	SceneManager::Get()->AddScene<TestScene>("test");
	SceneManager::Get()->ChangeSceneTo("test");
	
	InputManager* im = InputManager::Get();
	SDL_Event event;

	float DeltaTime = 0, TotalElapsed = 0;
	int FramCount = 0;
	Timer* fps = new Timer();
	bool run = true;
	while (run)
	{
		fps->StartTimer();
		window->ClearWindow();

		while (SDL_PollEvent(&event))
		{
			im->Update(event);
		}
		if (im->IsKeyDown(Key_echap))
		{
			delete window;
			SDL_Quit();
			run = false;
			continue;
		}

		SceneManager::Get()->UpdateActualScene(DeltaTime);
		SceneManager::Get()->DrawActualScene(window);

		window->Present();

		DeltaTime = fps->EndTimer();

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

	return 0;
}