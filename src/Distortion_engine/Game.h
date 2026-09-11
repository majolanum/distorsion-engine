#pragma once
#include <vector>

#include "SceneManager.h"

struct Window;

class Game
{
private:
	std::string m_Name;
	bool m_IsInitialized = false;

	float m_DeltaTime;
	void SetDeltaTime(float dt) { m_DeltaTime = dt; }

	void Initialize();
	void Update(float deltaTime);
	void DrawActualGame(Window* w);


protected:
	Game(std::string gameName) : m_Name(gameName) {}

	SceneManager* m_SceneManager;
	virtual void OnInitialize() {}
	virtual void OnUpdate() {}

	float GetDeltaTime() { return m_DeltaTime; }

	~Game();

	friend class Application;
};

