#include "main.h"
#include "Application/Application.h"
#include "Sample/SampleGame.h"
#include "Application/ApplicationInfo.h"
#include "Distortion_Engine/Utils.h"

int main(int argc, char* argv[])
{
	Application* App = Application::Get();
	bool* run = App->InitApplication();
	App->AddGame<SampleGame>("test",ApplicationInfo::GetTemplateLink());
	App->AddGame<SampleGame>("test2", "../../res/PlaceHolder2.png");


	while (*run)
		App->RunApplication();

	App->EndApplication();
	return 0;
}