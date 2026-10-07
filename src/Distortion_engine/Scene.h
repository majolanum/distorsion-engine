#pragma once

#include <vector>
#include <iostream>

#include "Lib2D/Drawable.h"
#include "Lib2D/Utils.h"
#include "Entity.h"

class Scene : public Drawable
{
private:
	std::vector<Entity*> m_AllEntity;
	std::vector<Entity*> m_EntityToDestroy;

	std::string m_SceneName;

	void Update(float DeltaTime);
	void DoCollide();
	void Draw(Window*)override;

protected:
	Scene(std::string sceneName);
	bool m_SceneCompleted = false;


	virtual void OnInitialize() {}
	virtual void OnUpdate() {}
	virtual void OnEnd() {}

	/// <summary>
	/// z axis : -1 = default -> after the last created entity
	/// collider type : 0 = non, 1 = rect, 2 = circle
	/// </summary>
	template<typename T>
	T* NewEntity(Vector2f* Position, int width, int height, std::string TexturPath, int zAxis = -1,
		bool canCollide = false, int colliderType = 0, bool haveRigBody = false);

	template<typename T>
	T* GetEntity();

	template<typename T>
	std::vector<T*> GetAllEntity();

	bool IsInside(Entity* entity);
	void RemoveEntity(Entity* entityToRemove, std::vector<Entity*>vector);

	~Scene();

	friend class SceneManager;
};

template<typename T>
inline T* Scene::NewEntity(Vector2f* Position, int width, int height, std::string TexturPath, int zAxis
	, bool canCollide, int colliderType, bool haveRigBody)
{
	T* NewEntity = new T(Position, width, height, TexturPath, canCollide, colliderType, haveRigBody);
	if (zAxis != -1)
		m_AllEntity.push_back(NewEntity);
	else
		m_AllEntity.emplace(zAxis, NewEntity);
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
