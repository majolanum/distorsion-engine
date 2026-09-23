#include "TestEntity.h"

void TestEntity::OnCollide(Entity* collideWith)
{
	if (dynamic_cast<TestEntity*>(collideWith))
	{
		EndScene = true;
	}
	
}
