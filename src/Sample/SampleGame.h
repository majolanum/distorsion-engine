#pragma once
#include "Distortion_engine\Game.h"

class SampleGame : public Game
{
public:
	using Game::Game;

	void OnInitialize() override;
	void OnUpdate() override;
	
};

