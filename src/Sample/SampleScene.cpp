#include "SampleScene.h"
#include "Application/ApplicationInfo.h"
#include "Lib2d/Debug.h"

void SampleScene::OnInitialize()
{
	Entity1 = NewEntity<SampleEntity>({ 50, 50 }, {50,50}, ApplicationInfo::GetTemplateLink());
	Entity2 = NewEntity<SampleEntity>({ 200, 200 }, { 50,50 }, ApplicationInfo::GetTemplateLink());

	Entity1->GoToPosition({ 200, 200 }, 10);
	ApplicationInfo::IsDebugDraw = true;

}

void SampleScene::OnUpdate()
{
	if (Entity1->EndScene)
	{
		m_SceneCompleted = true;
	}

}

