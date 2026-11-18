#include "SampleEntity.h"

void SampleEntity::OnInitialize()
{
	SetCollider(true, ColliderType::Circle);
	SetRigBody(true);
}

void SampleEntity::OnCollide(Entity* collideWith)
{
	if (dynamic_cast<SampleEntity*>(collideWith))
	{
		//EndScene = true;
	}
	
}
