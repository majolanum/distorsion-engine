#pragma once

#include <vector>
#include <iostream>

#include "Lib2D/Drawable.h"

class Entity;

class Scene : public Drawable
{
private:
	std::vector<Entity*> m_AllEntity;
	std::vector<Entity*> m_EntityToDestroy;
	std::vector<Entity*> m_EntityToAdd;

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
public:
	/// <summary>
	/// Creat a new Engine entity 
	/// </summary>
	/// <param name="zAxis">tell in wich order draw the entity, default -1 : after the last created entity</param>
	/// <returns></returns>
	template<typename T>
	T* NewEntity(Vector2f position, Vector2f size, std::string texturPath , int zAxis =-1);

	/// <summary>
	/// Creat a new Engine entity 
	/// </summary>
	/// <param name="zAxis">tell in wich order draw the entity, default -1 : after the last created entity</param>
	/// <returns></returns>
	template<typename T>
	T* NewEntity(Vector2f position, float radius, std::string texturPath , int zAxis =-1);

	template<typename T>
	T* GetEntity();

	template<typename T>
	std::vector<T*> GetAllEntity();

	/// <summary>
	/// Tell if the mouse is insinde the entity 
	/// </summary>
	bool IsInside(Entity* entity);
	void RemoveEntity(Entity* entityToRemove, std::vector<Entity*>&vector);

	~Scene();

	friend class SceneManager;
};

#include "Scene.inl"

