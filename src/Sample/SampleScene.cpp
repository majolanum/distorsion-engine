#include "SampleScene.h"
#include "Application/ApplicationInfo.h"
#include "Lib2d/Debug.h"

void SampleScene::OnInitialize()
{
	Entity1 = NewEntity<SampleEntity>({ 50, 50 }, 50.f, ApplicationInfo::GetTemplateLink());
	Entity2 = NewEntity<SampleEntity>({ 200, 200 }, 50.f, ApplicationInfo::GetTemplateLink());

	Entity1->GoToPosition({ 200, 200 }, 100);
	ApplicationInfo::IsDebugDraw = true;
	std::cout << Entity1->GetPosition().x << Entity1->GetPosition().y << std::endl;

}

void SampleScene::OnUpdate()
{	
	if (Entity1->EndScene)
	{
		m_SceneCompleted = true;
	}

}

