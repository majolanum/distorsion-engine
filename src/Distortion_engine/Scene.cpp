#include "Scene.h"
#include "InputManager.h"

Scene::Scene(std::string sceneName) : m_SceneName(sceneName)
{
	m_AllEntity.clear();
	m_EntityToDestroy.clear();
}

void Scene::Update(float DeltaTime)
{
	for (Entity* e : m_AllEntity)
	{
		e->Update(DeltaTime);

		if (e->ToDestroy)
		{
			RemoveEntity(e, m_AllEntity);
			m_EntityToDestroy.push_back(e);
		}
	}

	DoCollide();

	for (Entity* e : m_EntityToDestroy)
	{
		e->OnDestroy();
		delete e;
	}
	m_EntityToDestroy.clear();
}

void Scene::DoCollide()
{
	for (Entity* entity : m_AllEntity)
	{
		for (Entity* otherEntity : m_AllEntity)
		{
			if (entity != otherEntity)
			{
				if (entity->CanCollide && otherEntity->CanCollide)
				{
					if (entity->IsCollide(otherEntity))
					{
						entity->OnCollide(otherEntity);
						otherEntity->OnCollide(entity);

						if (entity->HaveRigBody && otherEntity->HaveRigBody)
						{
							//TODO : faire le repusle
							entity->Repulse();
							otherEntity->Repulse();
						}
					}
				}
			}
		}
	}
}

bool Scene::IsInside(Entity* entity)
{
	Vector2f* mousPos = InputManager::Get()->GetMousePosition();
	Vector2f* entityPos = entity->m_Position;
	float entityWidth = entity->m_Width;
	float entityHeight = entity->m_Height;

	if (entityPos->x < mousPos->x && entityPos->y < mousPos->y &&
		entityPos->x + entityWidth > mousPos->x && entityPos->y + entityHeight > mousPos->y)
		return true;
	else
		return false;
}

void Scene::RemoveEntity(Entity* entityToRemove, std::vector<Entity*> vector)
{
	int size = vector.size() - 1;

	for (int i = size; i >= 0; i--)
	{
		if (vector[i] == entityToRemove)
		{
			vector.erase(vector.begin() + i);
		}
	}
}

void Scene::Draw(Window* w)
{
	for (Entity* e : m_AllEntity)
	{
		e->Draw(w);
	}
}

Scene::~Scene()
{
	for (Entity* e : m_AllEntity)
	{
		e->OnDestroy();
		delete e;
	}
	m_AllEntity.clear();
	if (!m_EntityToDestroy.empty())
	{
		for (Entity* e : m_EntityToDestroy)
		{
			e->OnDestroy();
			delete e;
		}
	}
	m_EntityToDestroy.clear();
}