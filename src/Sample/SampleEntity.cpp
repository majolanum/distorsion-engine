#include "SampleEntity.h"
#include"SampleScene.h"
#include "Application/ApplicationInfo.h"

void SampleEntity::OnInitialize()
{
	SetRigBody(true);
	GetMyScene()->NewEntity<SampleEntity>({ 500,500 }, 50.f, ApplicationInfo::GetTemplateLink());
}

void SampleEntity::OnCollide(Entity* collideWith)
{
	if (dynamic_cast<SampleEntity*>(collideWith))
	{
		
	}
	
}
