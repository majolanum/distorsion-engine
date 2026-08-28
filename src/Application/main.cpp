#include <iostream>
#include <SDL.h>

#include "main.h"
#include "Lib2D/Window.h"
#include "Distortion_engine/Entity.h"
#include "Distortion_engine/Timer.h"

#include "Lib2D/InputManager.h"

#define TARGET_FPS 60
#define TARGET_ELAPSED 1000/TARGET_FPS


int main(int argc, char* argv[])
{
	std::cout << "Hello, World!\n";
	Window* window = new Window();
	window->OpenWindow();

	Entity* test = new Entity(new Vector2f(50, 50), "../../res/Lib2D/PlaceHolder.png");
	test->GoToPosition(new Vector2f(500, 500), 10);
	InputManager* im = InputManager::Get();
	SDL_Event event;

	float DeltaTime = 0, TotalElapsed = 0;
	int FramCount = 0;
	Timer *fps = new Timer();

	while (true)
	{
		fps->StartTimer();
		window->ClearWindow();

		while (SDL_PollEvent(&event))
		{
			im->Update(event);
		}
		
		test->Update(DeltaTime);
		test->Draw(window);

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

	delete window;
	return 0;
}