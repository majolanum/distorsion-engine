#pragma once
#include <vector>

#include "Scene.h"

class SceneManager
{
private:
	std::vector<Scene*> m_AllScene;
	Scene* m_ActualScene;

	void UpdateActualScene(float DeltaTime);
	void DrawActualScene(Window*);

public:
	bool ChangeSceneTo(std::string sceneName);
	bool SceneFinished() { return m_ActualScene->m_SceneCompleted; }

	template<typename T>
	void AddScene(std::string sceneName);

	template<typename T>
	T* GetActualScene();

	~SceneManager();

	friend class Game;
};

template<typename T>
inline void SceneManager::AddScene(std::string sceneName)
{
	T* newScene = new T(sceneName);
	m_AllScene.push_back(newScene);
}

template<typename T>
inline T* SceneManager::GetActualScene()
{	
	for (Scene* s : m_AllScene)
	{
		if (T* search = dynamic_cast<T*>(s))
			return search;
	}
	return nullptr;
}
