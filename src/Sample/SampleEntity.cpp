#include "SampleEntity.h"

void SampleEntity::OnInitialize()
{
	SetCollider(true, 1);
}

void SampleEntity::OnCollide(Entity* collideWith)
{
	if (dynamic_cast<SampleEntity*>(collideWith))
	{
		EndScene = true;
	}
	
}
