#include "SampleScene.h"
#include "Application/ApplicationInfo.h"
#include "Lib2d/Debug.h"

void SampleScene::OnInitialize()
{
	Entity1 = NewEntity<SampleEntity>({ 50, 50 }, {50,50}, ApplicationInfo::GetTemplateLink());
	Entity2 = NewEntity<SampleEntity>({ 200, 200 }, { 50,50 }, ApplicationInfo::GetTemplateLink());

	Entity1->SetCollider(true,1);
	Entity2->SetCollider(true, 1);

	Entity1->GoToPosition({ 200, 200 }, 10);
}

void SampleScene::OnUpdate()
{
	if (Entity1->EndScene)
	{
		m_SceneCompleted = true;
	}
	
	Debug::DrawLine(Entity1->GetPosition(), Entity2->GetPosition(),Color::White);

	Debug::DrawRect(Entity1->GetPosition(0,0), Entity1->GetSize(), Color::Yellow, false);
	Debug::DrawRect(Entity2->GetPosition(0,0), Entity1->GetSize(), Color::Red, false);
	
}

