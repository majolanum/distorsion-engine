#pragma once
#include "Distortion_engine\Scene.h"
#include "Application/GameIcon.h"
#include <map>

class SelecteGameScene : public Scene
{
private:
	std::vector<GameIcon*> m_AllGameIcon;
	std::vector<std::string> m_AllGameName;
	std::string m_SelectedGame;

protected:
	using Scene::Scene;
	void OnInitialize() override;
	void OnUpdate() override;

public:
	std::string GetChosenGame() { return m_SelectedGame; }
	void SetAllGame(std::map<std::string, std::string> gameList);
};

