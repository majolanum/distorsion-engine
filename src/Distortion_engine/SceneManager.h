#pragma once
#include <vector>

#include "Scene.h"

class SceneManager
{
	SceneManager();
	static SceneManager* instance;
private:
	std::vector<Scene*> m_AllScene;

	Scene* m_ActualScene;

protected:
	static SceneManager* Get();

	void UpdateActualScene(float DeltaTime);

	bool ChangeScene(std::string sceneName);

	template<typename T>
	void AddScene(std::string sceneName);

};

template<typename T>
inline void SceneManager::AddScene(std::string sceneName)
{
	T* newScene = new T(sceneName);
	m_AllScene.push_back(newScene);
	newScene.OnInitialize();
}
