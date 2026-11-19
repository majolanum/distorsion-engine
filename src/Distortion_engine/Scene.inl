#pragma once

#include "Scene.h"
#include "Entity.h"

template<typename T>
inline T* Scene::NewEntity(Vector2f position, Vector2f size, std::string texturPath, int zAxis)
{
	T* newEntity = new T();
	Entity* entity = static_cast<Entity*>(newEntity);

	entity->SetPosition(position);
	entity->SetSize(size);
	entity->zAxis = zAxis;
	entity->m_EntityType = EntityType::Rectangle;
	entity->SetCollider(true, ColliderType::Rectangle);
	entity->ChangeTexturePath(texturPath);

	entity->OnInitialize();

	m_EntityToAdd.push_back(newEntity);
	return newEntity;
}

template<typename T>
inline T* Scene::NewEntity(Vector2f position, float radius, std::string texturPath, int zAxis)
{
	T* newEntity = new T();
	Entity * entity = static_cast<Entity*>(newEntity);

	entity->SetPosition(position);
	entity->m_EntityType = EntityType::Circle;
	entity->zAxis = zAxis;
	entity->SetCollider(true, ColliderType::Circle, radius);
	entity->SetSize({ radius * 2,radius * 2 });
	entity->ChangeTexturePath(texturPath);

	entity->OnInitialize();

	m_EntityToAdd.push_back(newEntity);
	return newEntity;
}

template<typename T>
inline T* Scene::GetEntity()
{
	for (Entity* e : m_AllEntity)
	{
		if (T* search = dynamic_cast<T*>(e))
			return search;
	}
	return nullptr;
}

template<typename T>
inline std::vector<T*> Scene::GetAllEntity()
{
	std::vector<T*> StockTemp;
	for (Entity* e : m_AllEntity)
	{
		if (T* search = dynamic_cast<T*>(e))
			StockTemp.push_back(search);
	}
	if (StockTemp.empty())
		return nullptr;

	return StockTemp;
}
