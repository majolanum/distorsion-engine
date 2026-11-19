#include "SampleScene.h"
#include "Application/ApplicationInfo.h"
#include "Lib2d/Debug.h"

void SampleScene::OnInitialize()
{
	Entity1 = NewEntity<SampleEntity>({ 50, 50 }, 25, ApplicationInfo::GetTemplateLink());
	Entity2 = NewEntity<SampleEntity>({ 200, 300 }, 25, ApplicationInfo::GetTemplateLink());

	Entity1->SetRigBody(true);
	Entity2->SetRigBody(true);

	Entity1->GoToPosition(Entity2->GetPosition(), 100);
	ApplicationInfo::IsDebugDraw = true;	
}

void SampleScene::OnUpdate()
{
	if (Entity1->EndScene)
	{
		m_SceneCompleted = true;
	}
}

