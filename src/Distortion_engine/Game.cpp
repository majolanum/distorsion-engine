#include "Game.h"
void Game::Initialize()
{
	if (m_IsInitialized) return;
	m_IsInitialized = true;

	if (m_SceneManager == nullptr)
		m_SceneManager = new SceneManager();
	OnInitialize();
}

void Game::Update(float deltaTime)
{
	OnUpdate();
	m_SceneManager->UpdateActualScene(deltaTime);
}

void Game::DrawActualGame(Window* w)
{
	m_SceneManager->DrawActualScene(w);
}

Game::~Game()
{
	delete m_SceneManager;
	m_SceneManager = nullptr;
}