#include "TestScene.h"
#include "ApplicationInfo.h"

void TestScene::OnInitialize()
{
	Entity1 = NewEntity<TestEntity>(new Vector2f(50, 50), 50, 50, ApplicationInfo::GetTemplateLink(), true, 1);
	Entity2 = NewEntity<TestEntity>(new Vector2f(200, 200), 50, 50, ApplicationInfo::GetTemplateLink(), true, 1);
	Entity1->GoToPosition(new Vector2f(200, 200), 10);
}

void TestScene::OnUpdate()
{
	if (Entity1->EndScene)
	{
		m_SceneCompleted = true;
	}
}

