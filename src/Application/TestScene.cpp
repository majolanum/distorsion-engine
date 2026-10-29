#include "TestScene.h"
#include "ApplicationInfo.h"
#include "Lib2d/Debug.h"

void TestScene::OnInitialize()
{
	Entity1 = NewEntity<TestEntity>(new Vector2f(50, 50), 50, 50, ApplicationInfo::GetTemplateLink());
	Entity2 = NewEntity<TestEntity>(new Vector2f(200, 200), 50, 50, ApplicationInfo::GetTemplateLink());

	Entity1->SetCollider(true,1);
	Entity2->SetCollider(true, 1);

	Entity1->GoToPosition(new Vector2f(200, 200), 10);
}

void TestScene::OnUpdate()
{
	if (Entity1->EndScene)
	{
		m_SceneCompleted = true;
	}
	
	Debug::DrawLine(*Entity1->GetPosition(), *Entity2->GetPosition(),Color::White);

	Debug::DrawRect(*Entity1->GetPosition(), { Entity1->GetWidth(),Entity1->GetHeight() }, Color::Yellow, false);
	Debug::DrawRect(*Entity2->GetPosition(), { Entity2->GetWidth(),Entity2->GetHeight() }, Color::Red, false);
	
}

