#pragma once

#include <vector>
#include <iostream>

#include "Lib2D/Drawable.h"
#include "Entity.h"

class Scene : public Drawable
{
private:
	std::vector<Entity*> m_AllEntity;
	std::vector<Entity*> m_EntityToDestroy;

	std::string m_SceneName;

	void Update(float DeltaTime);

protected:
	Scene(std::string sceneName);

	virtual void OnInitialize() {}
	virtual void OnUpdate() {}

	/// <summary>
/// collider type : 0 = non, 1 = rect, 2 circle
/// </summary>
	template<typename T>
	T* NewEntity(Vector2f* Position, int width, int height, bool canCollide = false,
		int colliderType = 0, std::string TexturPath = "../../res/Lib2D/PlaceHolder.png");

	template<typename T>
	T* GetEntity();

	template<typename T>
	std::vector<T*> GetAllEntity();

	void RemoveEntity(Entity* entityToRemove, std::vector<Entity*>vector);
	void Draw(Window*)override;

	~Scene();

	friend class SceneManager;
};

template<typename T>
inline T* Scene::NewEntity(Vector2f* Position, int width, int height, bool canCollide,
	int colliderType, std::string TexturPath)
{
	T* NewEntity = new T(Position, width, height, TexturPath, canCollide, colliderType);
	m_AllEntity.push_back(NewEntity);
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
