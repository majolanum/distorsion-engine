#include "TestScene.h"

void TestScene::OnInitialize()
{
	NewEntity<Entity>(new Vector2f(50, 50), 50, 50)->GoToPosition(new Vector2f(200, 200), 1.f);
}

void TestScene::OnUpdate()
{
}

