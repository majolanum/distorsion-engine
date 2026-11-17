#pragma once
#include "Distortion_Engine/Entity.h"

class SampleEntity : public Entity
{
public:
	
	bool EndScene = false;
	void OnInitialize() override;
	void OnCollide(Entity* collideWith) override;

};

