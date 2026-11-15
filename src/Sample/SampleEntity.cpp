#include "SampleEntity.h"

void SampleEntity::OnCollide(Entity* collideWith)
{
	if (dynamic_cast<SampleEntity*>(collideWith))
	{
		EndScene = true;
	}
	
}
