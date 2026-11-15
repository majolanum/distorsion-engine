#pragma once
#include "Distortion_engine\Game.h"
#include "SampleScene.h"

class SampleGame : public Game
{
public:
	using Game::Game;

	void OnInitialize() override;
	void OnUpdate() override;
	
};

