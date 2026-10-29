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
	void DoCollide();
	void Draw(Window*)override;

protected:
	Scene(std::string sceneName);
	bool m_SceneCompleted = false;


	virtual void OnInitialize() {}
	virtual void OnUpdate() {}
	virtual void OnEnd() {}

	/// <summary>
	/// Creat a new Engine entity 
	/// </summary>
	/// <param name="zAxis">tell in wich order draw the entity, default -1 : after the last created entity</param>
	/// <returns></returns>
	template<typename T>
	T* NewEntity(Vector2f* position, int width, int height, std::string TexturPath, int zAxis =-1);

	template<typename T>
	T* GetEntity();

	template<typename T>
	std::vector<T*> GetAllEntity();

	/// <summary>
	/// Tell if the mouse is insinde the entity 
	/// </summary>
	bool IsInside(Entity* entity);
	void RemoveEntity(Entity* entityToRemove, std::vector<Entity*>vector);

	~Scene();

	friend class SceneManager;
};

template<typename T>
inline T* Scene::NewEntity(Vector2f* position, int width, int height, std::string TexturPath, int zAxis)
{
	T* NewEntity = new T(position, width, height, TexturPath);

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
