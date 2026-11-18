#pragma once
#include <string>

#include "Lib2D/Sprite.h"
#include "Lib2D/Collider.h"

enum class EntityType
{
	Rectangle = 1,
	Circle = 2,
};


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
	bool toDestroy = false;
	bool CanCollide = false;
	bool HaveRigBody = false;

	EntityType m_EntityType = EntityType::Rectangle;
	Vector2f Velocity = {};

	void Move(float deltaTime);
	void Update(float deltaTime);
	void Draw(Window*) override;
	bool IsAtTarget();
	void Repulse(Entity* other);
	void CircleRepulse(Entity* other);
	void RctangleRepulse(Entity* other);

protected:
	Entity() : Sprite() {};

	virtual void OnInitialize() {}
	virtual void OnUpdate() {}
	virtual void OnCollide(Entity* collideWith) {}
	virtual void OnDestroy() {}

	int GetIndex() const { return m_Index; }
public:

	/// <summary>
	/// Set if the entity can collide with other entity.
	/// If type 1 : radius = -1
	/// </summary>
	void SetCollider(bool newState, ColliderType newType, float newRadius = -1);

	void SetRigBody(bool newState) { HaveRigBody = newState; }
	void SetIndex(int index) { m_Index = index; }

	void SetSize(Vector2f newSize) { m_Width = newSize.x, m_Height = newSize.y; }
	void SetSize(float newRadius) { m_Radius = newRadius; }

	void SetPosition(Vector2f position, float anchorX = 0.5f, float anchorY = 0.5f);
	Vector2f GetPosition(float anchorX = 0.5f, float anchorY = 0.5f);
	
	void GoToPosition(Vector2f position, float speed = -1);
	void GoToDirection(Vector2f position, float speed = -1);

	void Destroy();

	friend class Collider;
	friend class Scene;
};
