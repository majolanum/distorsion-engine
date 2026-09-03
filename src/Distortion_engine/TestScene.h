#pragma once
#include "Scene.h"
class TestScene : public Scene
{
public :
	TestScene(std::string name) : Scene(name) {}
	void OnInitialize() override;
	void OnUpdate() override;
};

