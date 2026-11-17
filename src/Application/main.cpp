#include "main.h"
#include "Application/Application.h"
#include "Application/ApplicationInfo.h"
#include "Sample/SampleGame.h"

int main(int argc, char* argv[])
{
	Application* App = Application::Get();
	App->AddGame<SampleGame>("test",ApplicationInfo::GetTemplateLink());
	App->AddGame<SampleGame>("test2", "../../res/PlaceHolder2.png");
	App->LauchApp();

	return 0;
}