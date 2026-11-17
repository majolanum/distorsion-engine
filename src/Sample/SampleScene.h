#pragma once
#include "Distortion_engine/Scene.h"
#include "SampleEntity.h"

class SampleScene : public Scene
{
private: 
	SampleEntity* Entity1 = nullptr;
	SampleEntity* Entity2 = nullptr;

public :
	SampleScene(std::string name) : Scene(name) {}
	void OnInitialize() override;
	void OnUpdate() override;
};

