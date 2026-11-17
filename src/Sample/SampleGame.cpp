#include "SampleGame.h"
#include "SampleScene.h"

void SampleGame::OnInitialize()
{
	m_SceneManager->AddScene<SampleScene>("test");
	m_SceneManager->ChangeSceneTo("test");
}

void SampleGame::OnUpdate()
{
	if (m_SceneManager->SceneFinished())
	{
		IsRuning = false;
	}
}
