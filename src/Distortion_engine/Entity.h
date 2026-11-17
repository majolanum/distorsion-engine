#pragma once
#include <string>

#include "Lib2D/Sprite.h"
#include "Lib2D/Collider.h"

class Entity : public Sprite, public Collider
{
	struct Target
	{
		Vector2f TargetPosition = {};
		Vector2f TargetDirection = {};
		bool IsSet = false;
	} m_Target;

private:
	int m_Speed = 0;
	int m_Index = 0;
	bool ToDestroy = false;
	bool CanCollide = false;
	bool HaveRigBody = false;

	void Move(float deltaTime);
	void Update(float deltaTime);
	void Draw(Window*) override;
	bool IsAtTarget();
	void Repulse();

protected:
	Entity() : Sprite() {};

	virtual void OnInitialize() {}
	virtual void OnUpdate() {}
	virtual void OnCollide(Entity* collideWith) {}
	virtual void OnDestroy() {}

	void SetIndex(int index) { m_Index = index; }
	int GetIndex() const { return m_Index; }
public:

	/// <summary>
	/// Set if the entity can collide with other entity
	/// </summary>
	///<param name = "newType"> collider type : 0 = non, 1 = rect, 2 = circle</param>
	void SetCollider(bool newState, int newType);

	void SetRigBody(bool newState) { HaveRigBody = newState; }

	void SetSize(Vector2f newSize) { m_Width = newSize.x, m_Height = newSize.y; }

	void SetPosition(Vector2f position) { m_Position = position; }
	Vector2f GetPosition(float anchorX = 0.5f, float anchorY = 0.5f);
	
	void GoToPosition(Vector2f position, float speed = -1);

	void GoToDirection(Vector2f position, float speed = -1);

	friend class Collider;
	friend class Scene;
};
