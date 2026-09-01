#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

SceneManager* SceneManager::Get()
{
	if (instance == nullptr)
	{
		instance = new SceneManager();
	}
	return instance;
}

void SceneManager::UpdateActualScene(float DeltaTime)
{
	m_ActualScene->Update(DeltaTime);
}

bool SceneManager::ChangeScene(std::string sceneName)
{
	for (Scene* scene : m_AllScene)
	{
		if (scene->m_SceneName == sceneName)
		{
			m_ActualScene = scene;
			return true;
		}
	}
	return false;
}
