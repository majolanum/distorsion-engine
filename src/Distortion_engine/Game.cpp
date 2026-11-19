#include "Game.h"

void Game::Initialize()
{
	if (m_IsInitialized) 
		return;
	m_IsInitialized = true;

	if (m_SceneManager == nullptr)
		m_SceneManager = new SceneManager();
	OnInitialize();
	IsRuning = true;
}

void Game::Update(float deltaTime)
{
	m_SceneManager->UpdateActualScene(deltaTime);
	OnUpdate();
}

void Game::DrawActualGame(Window* w)
{
	m_SceneManager->DrawActualScene(w);
}

void Game::EndGame()
{
	if(m_SceneManager)
		delete m_SceneManager;
	m_SceneManager = nullptr;
	m_IsInitialized = false;
}

Game::~Game()
{
	EndGame();
	m_Name.clear();	
}