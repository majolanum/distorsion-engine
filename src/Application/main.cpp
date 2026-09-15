#include <iostream>
#include "main.h"
#include "Application/Application.h"
#include "Application/TestGame.h"

int main(int argc, char* argv[])
{
	Application* App = Application::Get();

	bool* run = App->InitApplication();
	App->AddGame<TestGame>("test");
	
	while (*run)
		App->RunApplication();

	App->EndApplication();
	return 0;
}