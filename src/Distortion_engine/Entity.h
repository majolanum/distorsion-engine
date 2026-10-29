#pragma once
#include <string>

#include "Lib2D/Sprite.h"
#include "Lib2D/Collider.h"

class Entity : public Sprite, public Collider
{
	struct Target
	{
		Vector2f* TargetPosition = nullptr;
		Vector2f* TargetDirection = nullptr;
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
	Entity(Vector2f* Position, int width, int height, std::string TexturPath);

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
	void SetCollider(bool newState, int newType) { CanCollide = newState; SetColliderType(newType); }

	/// <summary>
	/// Set if the entity push the other entity when collide with him
	/// </summary>
	void SetRigBody(bool newState) { HaveRigBody = newState; }

	void SetPosition(Vector2f* Position) { m_Position = Position; }
	Vector2f* GetPosition() const { return m_Position; }

	void GoToPosition(Vector2f* Position, float speed = -1);

	void GoToDirection(Vector2f* position, float speed = -1);

	friend class Collider;
	friend class Scene;
};
