#pragma once
#include "Distortion_engine/Scene.h"
#include "SampleEntity.h"

class SampleScene : public Scene
{
private: 
	SampleEntity* Entity1;
	SampleEntity* Entity2;

public :
	SampleScene(std::string name) : Scene(name) {}
	void OnInitialize() override;
	void OnUpdate() override;
};

