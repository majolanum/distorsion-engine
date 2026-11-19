#include "SampleEntity.h"
#include"SampleScene.h"
#include "Application/ApplicationInfo.h"

void SampleEntity::OnInitialize()
{
	SetRigBody(true);
}

void SampleEntity::OnUpdate()
{
	
}

void SampleEntity::OnCollide(Entity* collideWith)
{
	if (dynamic_cast<SampleEntity*>(collideWith))
	{
		isCollide = true;
	}
	
}
