#include "SelecteGameScene.h"
#include "Application/ApplicationInfo.h"
#include "Distortion_engine/InputManager.h"

void SelecteGameScene::OnInitialize()
{
	m_SelectedGame.clear();
	m_AllGameIcon.clear();
	m_AllGameName.clear();
}

void SelecteGameScene::OnUpdate()
{
	for (GameIcon* GI : m_AllGameIcon)
	{
		if (IsInside(GI) && InputManager::Get()->IsKeyDown(Mouse_Left))
		{
			m_SceneCompleted = true;
			m_SelectedGame = GI->GetGameName();
		}
	}
}

void SelecteGameScene::SetAllGame(std::map<std::string, std::string> gameList)
{
	float windowWidth = ApplicationInfo::GetWindowWidth();
	float windowHeight = ApplicationInfo::GetWindowHeight();
	int iconSize = 100;


	switch (gameList.size())
	{
	case 1:
	{
		Vector2f* pos = new Vector2f((windowWidth / 2) - iconSize / 2, (windowHeight / 2) - iconSize / 2);

		auto it = gameList.begin();
		GameIcon* GI = NewEntity<GameIcon>(pos, iconSize, iconSize, it->first);
		GI->SetGameName(it->second);
		m_AllGameIcon.push_back(GI);
		break;
	}
	case 2:
	{
		float posX1 = (windowWidth / 3) - iconSize / 2;
		float posY1 = (windowHeight / 3) - iconSize / 2;
		int iterator = 1;

		for (auto it = gameList.begin(); it != gameList.end(); ++it)
		{
			Vector2f* pos = new Vector2f(posX1 * iterator, posY1);
			GameIcon* GI = NewEntity<GameIcon>(pos, iconSize, iconSize, it->first);
			GI->SetGameName(it->second);
			m_AllGameIcon.push_back(GI);
			iterator++;
		}
		break;
	}
	}
}
