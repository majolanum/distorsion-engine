#include "TestGame.h"

void TestGame::OnInitialize()
{
	m_SceneManager->AddScene<TestScene>("test");
	m_SceneManager->ChangeSceneTo("test");
}

void TestGame::OnUpdate()
{
	if (m_SceneManager->SceneFinished())
	{
		IsRuning = false;
	}
}
