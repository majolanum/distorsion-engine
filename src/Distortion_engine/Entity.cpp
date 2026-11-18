#include <iostream>
#include "Entity.h"
#include "Lib2D/Debug.h"
#include "Application/ApplicationInfo.h"


bool Entity::IsAtTarget()
{
	if (m_Target.IsSet)
	{
		float distanceToTargetX = m_Target.TargetPosition.x - m_Position.x;
		float distanceToTargetY = m_Target.TargetPosition.y - m_Position.y;

		if (distanceToTargetX < 0.2f || distanceToTargetY < 0.2f)
		{
			return true;
		}
		else
			return false;
	}
	else
		return false;
}

void Entity::Repulse(Entity* other)
{
	if (m_ColliderType == ColliderType::Circle && other->m_ColliderType == ColliderType::Circle)
		CircleRepulse(other);
	if (m_ColliderType == ColliderType::Rectangle && other->m_ColliderType == ColliderType::Circle)
	{
	}
	if (m_ColliderType == ColliderType::Rectangle && other->m_ColliderType == ColliderType::Rectangle)
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

Vector2f Entity::GetPosition(float anchorX, float anchorY)
{
	Vector2f pos = { 0,0 };
	if (m_ColliderType == ColliderType::Circle)
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
	m_Target.IsSet = false;

	m_Speed = speed;

	float targetDirectionX = m_Target.TargetPosition.x - m_Position.x;
	float targetDirectionY = m_Target.TargetPosition.y - m_Position.y;

	m_Target.TargetDirection = { targetDirectionX, targetDirectionY };
	m_Target.TargetDirection.Normalize();

	Velocity = m_Target.TargetDirection + speed;
	m_Target.IsSet = true;
}

void Entity::GoToPosition(Vector2f position, float speed)
{
	GoToDirection(position, speed);
	m_Target.TargetPosition = position;
}

void Entity::Move(float deltaTime)
{
	if (IsAtTarget())
	{
		SetPosition(m_Target.TargetPosition);
		m_Target.IsSet = false;
	}
	if (m_Target.IsSet)
	{
		float distance = deltaTime * m_Speed;
		Vector2f translation = { distance * m_Target.TargetDirection.x, distance * m_Target.TargetDirection.y
		};

		m_Position += Velocity* deltaTime;

	}
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
		if (m_ColliderType == ColliderType::Rectangle)
			Debug::DrawRect(GetPosition(0, 0), GetSize(), Color::Yellow, false);
		else if (m_ColliderType == ColliderType::Circle)
			Debug::DrawCircle(GetPosition(), m_Radius, Color::Yellow);

		//if (m_Target.IsSet)
			//Debug::DrawLine(GetPosition(), m_Target.TargetPosition, Color::Orange);
	}

	Sprite::Draw(w);
}