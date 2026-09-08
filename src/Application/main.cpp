#include <iostream>
#include "main.h"
#include "Application/Application.h"

int main(int argc, char* argv[])
{
	std::cout << "Hello, World!\n";
	Application* App = new Application();

	bool run = App->InitApplication();

	while (run)
		App->RunApplication(&run);

	App->EndApplication();
	return 0;
}