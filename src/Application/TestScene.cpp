#include "TestScene.h"

void TestScene::OnInitialize()
{
	NewEntity<Entity>(new Vector2f(50, 50), 50, 50,true)->GoToPosition(new Vector2f(200, 200), 1.f);
	NewEntity<Entity>(new Vector2f(200, 200), 50, 50,true);
}

void TestScene::OnUpdate()
{
}

