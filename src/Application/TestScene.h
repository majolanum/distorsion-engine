#pragma once
#include "Scene.h"
#include <TestEntity.h>

class TestScene : public Scene
{
private: 
	TestEntity* Entity1;
	TestEntity* Entity2;

public :
	TestScene(std::string name) : Scene(name) {}
	void OnInitialize() override;
	void OnUpdate() override;
};

