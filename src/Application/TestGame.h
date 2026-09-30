#pragma once
#include "Distortion_engine\Game.h"
#include "TestScene.h"

class TestGame : public Game
{
public:
	using Game::Game;

	void OnInitialize() override;
	void OnUpdate() override;
	
};

