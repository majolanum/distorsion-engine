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

	~SceneManager();

	friend class Game;
};

template<typename T>
inline void SceneManager::AddScene(std::string sceneName)
{
	T* newScene = new T(sceneName);
	m_AllScene.push_back(newScene);
}
