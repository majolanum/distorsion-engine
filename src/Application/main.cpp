#include <iostream>
#include "main.h"
#include "Application/Application.h"
#include "Distortion_engine/Game.h"

int main(int argc, char* argv[])
{
	std::cout << "Hello, World!\n";
	Application* App = new Application();

	bool run = App->InitApplication();
	App->AddGame<Game>("test");
	App->ChangeGame("test");

	while (run)
		App->RunApplication(&run);

	App->EndApplication();
	return 0;
}