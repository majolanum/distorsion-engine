#include "SceneManager.h"

void SceneManager::UpdateActualScene(float DeltaTime)
{
	m_ActualScene->Update(DeltaTime);
	m_ActualScene->OnUpdate();
}

void SceneManager::DrawActualScene(Window*w)
{
	m_ActualScene->Draw(w);
}

bool SceneManager::ChangeSceneTo(std::string sceneName)
{
	for (Scene* scene : m_AllScene)
	{
		if (scene->m_SceneName == sceneName)
		{
			m_ActualScene = scene;
			m_ActualScene->OnInitialize();
			return true;
		}
	}
	return false;
}

SceneManager::~SceneManager()
{

	for (Scene* s : m_AllScene)
	{
		delete s;
	}
	m_AllScene.clear();
}
