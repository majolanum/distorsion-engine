#include <iostream>
#include "Entity.h"
#include "Lib2D/Debug.h"
#include "Application/ApplicationInfo.h"


bool Entity::IsAtTarget()
{
	if (m_Target.IsSet)
	{
		Vector2f distanceToTarget = m_Target.TargetPosition - m_Position;
		if (distanceToTarget.Magnitude() < 0.2f)
			return true;
		else
			return false;
	}
	else
		return false;
}

void Entity::Repulse(Entity* other)
{
	if (m_EntityType == EntityType::Circle && other->m_EntityType == EntityType::Circle)
		CircleRepulse(other);
	if (m_EntityType == EntityType::Rectangle && other->m_EntityType == EntityType::Circle)
	{
	}
	if (m_EntityType == EntityType::Rectangle && other->m_EntityType == EntityType::Rectangle)
		RctangleRepulse(other);
}

void Entity::CircleRepulse(Entity* other)
{
	Vector2f AB = other->GetPosition() - GetPosition();
	Vector2f normal = AB.Normalize();

	float distance = AB.Magnitude();
	float overlap = m_Radius + other->m_Radius - distance;

	m_Position -= normal * (overlap * 0.5f);
	other->m_Position += normal * (overlap * 0.5f);

	Vector2f vnA = normal * Vector2f::Dot(Velocity, normal);
	Vector2f vtA = Velocity - vnA;
	Vector2f vnB = normal * Vector2f::Dot(other->Velocity, normal);
	Vector2f vtB = other->Velocity - vnB;

	Velocity = vnB + vtA;
	other->Velocity = vnA + vtB;

	if (m_Target.IsSet)
		GoToDirection(m_Target.TargetPosition, m_Speed);
}

void Entity::RctangleRepulse(Entity* other)
{
}

void Entity::SetCollider(bool newState, ColliderType newType, float newRadius)
{
	CanCollide = newState;
	m_ColliderType = newType;
	m_Radius = newRadius;
	if (newType == ColliderType::Circle && newRadius == -1)
	{
		if (m_Width < m_Height)
			m_Radius = m_Height / 2;
		else
			m_Radius = m_Width / 2;
	}
}

void Entity::SetPosition(Vector2f position, float anchorX, float anchorY)
{
	if (m_EntityType == EntityType::Circle)
	{
		float size = m_Radius * 2.0f;
		m_Position.x = position.x + size * anchorX;
		m_Position.y = position.y + size * anchorY;
	}
	else
	{		
		m_Position.x = position.x + m_Width * anchorX;
		m_Position.y = position.y + m_Height * anchorY;
	}
}

Vector2f Entity::GetPosition(float anchorX, float anchorY)
{
	Vector2f pos = { 0,0 };
	if (m_EntityType == EntityType::Circle)
	{
		float size = m_Radius * 2.0f;
		pos.x = m_Position.x + size * anchorX;
		pos.y = m_Position.y + size * anchorY;
	}
	else
	{
		pos.x = m_Position.x + m_Width * anchorX;
		pos.y = m_Position.y + m_Height * anchorX;
	}return pos;
}

void Entity::GoToDirection(Vector2f position, float speed)
{
	m_Speed = speed;
	m_Target.TargetPosition = position;

	m_Target.TargetDirection =m_Target.TargetPosition - m_Position;
	m_Target.TargetDirection.Normalize();

	Velocity = m_Target.TargetDirection * speed;
}

void Entity::GoToPosition(Vector2f position, float speed)
{
	GoToDirection(position, speed);
	m_Target.IsSet = true;
}

void Entity::Move(float deltaTime)
{
	if (IsAtTarget())
	{
		SetPosition(m_Target.TargetPosition);
		m_Target.IsSet = false;
		Velocity = { 0,0 };
	}

	m_Position += Velocity * deltaTime;
}

void Entity::Update(float deltaTime)
{
	Move(deltaTime);
	UpdateCollider(GetPosition(), m_Width, m_Height);
}

void Entity::Draw(Window* w)
{
	if (ApplicationInfo::IsDebugDraw)
	{
		if (m_EntityType == EntityType::Rectangle)
			Debug::DrawRect(GetPosition(0, 0), GetSize(), Color::Yellow, false);
		else if (m_EntityType == EntityType::Circle)
			Debug::DrawCircle(GetPosition(), m_Radius, Color::Yellow);

		if (m_Target.IsSet)
			Debug::DrawLine(GetPosition(), m_Target.TargetPosition, Color::Red);
	}

	Sprite::Draw(w);
}

void Entity::Destroy()
{
	toDestroy = true;
	OnDestroy();
}