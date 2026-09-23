#pragma once
#include "Distortion_engine\Game.h"
#include "SelecteGameScene.h"

class SelectGameG : public Game
{
private:
	SelecteGameScene* m_SelectGameScene;
	std::vector<Game*> m_AllGame;

protected:
	using Game::Game;
	void OnInitialize() override;
	void OnUpdate() override;

public:
	bool SetAllGame(std::vector<Game*> allGame);
	friend class Application;
};

