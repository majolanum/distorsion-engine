#include "main.h"
#include "Application/Application.h"
#include "Application/TestGame.h"
#include "Application/ApplicationInfo.h"

//#include<SDL3_mixer/SDL_mixer.h>

int main(int argc, char* argv[])
{
	Application* App = Application::Get();
	//MIX_CreateMixer(NULL);
	bool* run = App->InitApplication();
	App->AddGame<TestGame>("test",ApplicationInfo::GetTemplateLink());
	App->AddGame<TestGame>("test2", "../../res/PlaceHolder2.png");
	
	while (*run)
		App->RunApplication();

	App->EndApplication();
	return 0;
}