#pragma once
#include "Distortion_Engine/Entity.h"

class SampleEntity : public Entity
{
public:
	using Entity::Entity;

	bool EndScene = false;
	void OnCollide(Entity* collideWith) override;

};

