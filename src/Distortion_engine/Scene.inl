#pragma once

#include "Scene.h"
#include "Entity.h"

template<typename T>
inline T* Scene::NewEntity(Vector2f position, Vector2f size, std::string texturPath, int zAxis)
{
	T* NewEntity = new T();
	static_cast<Entity*>(NewEntity)->SetPosition(position);
	static_cast<Entity*>(NewEntity)->SetSize(size);
	static_cast<Entity*>(NewEntity)->m_EntityType = EntityType::Rectangle;
	static_cast<Entity*>(NewEntity)->SetCollider(true, ColliderType::Rectangle);
	static_cast<Entity*>(NewEntity)->ChangeTexturePath(texturPath);

	static_cast<Entity*>(NewEntity)->OnInitialize();

	if (zAxis == -1)
		m_AllEntity.push_back(NewEntity);
	else
		m_AllEntity.emplace(m_AllEntity.begin() + zAxis, NewEntity);

	return NewEntity;
}

template<typename T>
inline T* Scene::NewEntity(Vector2f position, float radius, std::string texturPath, int zAxis)
{
	T* NewEntity = new T();
	static_cast<Entity*>(NewEntity)->SetPosition(position);	
	static_cast<Entity*>(NewEntity)->m_EntityType = EntityType::Circle;
	static_cast<Entity*>(NewEntity)->SetCollider(true, ColliderType::Circle, radius);
	static_cast<Entity*>(NewEntity)->SetSize({radius*2,radius*2});
	static_cast<Entity*>(NewEntity)->ChangeTexturePath(texturPath);

	static_cast<Entity*>(NewEntity)->OnInitialize();

	if (zAxis == -1)
		m_AllEntity.push_back(NewEntity);
	else
		m_AllEntity.emplace(m_AllEntity.begin() + zAxis, NewEntity);

	return NewEntity;
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
