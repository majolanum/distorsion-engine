#pragma once
#include <vector>

#include "SceneManager.h"

struct Window;

class Game
{
private:
	std::string m_Name;
	std::string m_GameIconLink;
	bool m_IsInitialized = false;

	void Initialize();
	void Update(float deltaTime);
	void DrawActualGame(Window* w);
	void EndGame();

protected:
	Game(std::string gameName, std::string gameIconLink) : m_Name(gameName), m_GameIconLink(gameIconLink) {}
	bool IsRuning;

	SceneManager* m_SceneManager;
	virtual void OnInitialize() {}
	virtual void OnUpdate() {}

	~Game();

public:
	friend class Application;
	friend class SelectGameG;
};
