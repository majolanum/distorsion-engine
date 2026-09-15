#pragma once
#include <vector>

#include "SceneManager.h"

struct Window;

class Game
{
private:
	std::string m_Name;
	bool m_IsInitialized = false;

	void Initialize();
	void Update(float deltaTime);
	void DrawActualGame(Window* w);
	void EndGame();

protected:
	Game(std::string gameName) : m_Name(gameName) {}
	bool IsRuning;

	SceneManager* m_SceneManager;
	virtual void OnInitialize() {}
	virtual void OnUpdate() {}

	~Game();

public:
	friend class Application;
};
