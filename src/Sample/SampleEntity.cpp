#include "SampleEntity.h"

void SampleEntity::OnInitialize()
{
	SetRigBody(true);
}

void SampleEntity::OnCollide(Entity* collideWith)
{
	if (dynamic_cast<SampleEntity*>(collideWith))
	{
		Destroy();
	}
	
}
