#pragma once
#include "Distortion_Engine/Entity.h"

class SampleEntity : public Entity
{
public:
	bool isCollide = false;

	bool EndScene = false;
	void OnInitialize() override;
	void OnUpdate() override;
	void OnCollide(Entity* collideWith) override;

};

