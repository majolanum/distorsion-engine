#pragma once
#include <vector>

#include "Scene.h"

class SceneManager
{
private:
	std::vector<Scene*> m_AllScene;
	Scene* m_ActualScene;

public:

	void UpdateActualScene(float DeltaTime);
	void DrawActualScene(Window*);

	bool ChangeSceneTo(std::string sceneName);

	template<typename T>
	void AddScene(std::string sceneName);
};

template<typename T>
inline void SceneManager::AddScene(std::string sceneName)
{
	T* newScene = new T(sceneName);
	m_AllScene.push_back(newScene);
}
