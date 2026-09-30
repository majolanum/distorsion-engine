#pragma once
#include <Entity.h>

class TestEntity : public Entity
{
public:
	using Entity::Entity;

	bool EndScene = false;
	void OnCollide(Entity* collideWith) override;

};

