#pragma once
#include "Distortion_engine\Game.h"
#include "TestScene.h"

class TestGame : public Game
{
public:
	TestGame(std::string gameName) : Game(gameName) {}

	void OnInitialize() override;
	void OnUpdate() override;
	
};

