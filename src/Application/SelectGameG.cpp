#include "SelectGameG.h"
#include "Application.h"
#include <map>

void SelectGameG::OnInitialize()
{
	m_SceneManager->AddScene<SelecteGameScene>("Select_game");
	m_SceneManager->ChangeSceneTo("Select_game");

	m_SelectGameScene = m_SceneManager->GetActualScene<SelecteGameScene>();
	m_AllGame.clear();
}

void SelectGameG::OnUpdate()
{
	if (m_SceneManager->SceneFinished())
	{
		Application::Get()->ChangeGame(m_SelectGameScene->GetChosenGame());
		IsRuning = false;
	}
}

bool SelectGameG::SetAllGame(std::vector<Game*> allGame)
{
	std::map<std::string, std::string> gameList;
	
	for (Game* g : allGame)
	{
		if (g == this)
			continue;
		if (g->m_GameIconLink != "")
		{
			gameList.emplace( g->m_GameIconLink, g->m_Name);
		}
	}
	if (!gameList.empty())
	{
		m_SelectGameScene->SetAllGame(gameList);
		return true;
	}
	else
		return false;
}
