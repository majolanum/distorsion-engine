#include <iostream>
#include "main.h"
#include "Application/Application.h"
#include "Application/TestGame.h"

int main(int argc, char* argv[])
{
	std::cout << "Hello, World!\n";
	Application* App = new Application();

	bool* run = App->InitApplication();
	App->AddGame<TestGame>("test");
	App->ChangeGame("test");

	while (*run)
		App->RunApplication();

	App->EndApplication();
	return 0;
}