#include <iostream>
#include <assert.h>
#include "Entity.h"
#include "Game.h"
#include "Lib2D/Debug.h"
#include "Application/ApplicationInfo.h"

bool Entity::IsAtTarget()
{
	if (m_Target.IsSet)
	{
		Vector2f distanceToTarget = m_Target.TargetPosition - GetPosition();
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
	m_Target.IsSet = false;
}

void Entity::CircleRepulse(Entity* other)
{
	Vector2f AB = other->GetPosition() - GetPosition();
	Vector2f normal = AB.GetNormalize();
	float overlap = m_Radius + other->m_Radius - AB.Magnitude();

	assert(overlap >= 0);

	Vector2f relativeVelocity = m_Velocity - other->m_Velocity;
	float closingSpeed = Vector2f::Dot(relativeVelocity, normal);

	float totalWeight = m_Physique.weight + other->m_Physique.weight;
	float ratioA = other->m_Physique.weight / totalWeight;
	float ratioB = m_Physique.weight / totalWeight;

	m_Position -= normal * (overlap * ratioA);
	other->m_Position += normal * (overlap * ratioB);

	Vector2f newAVelocity = (normal * -1) * (closingSpeed * ratioA);
	Vector2f newBVelocity = normal * (closingSpeed * ratioB);

	m_Velocity += newAVelocity;
	other->m_Velocity += newBVelocity;

	float totalRestitutionCoef = (m_Physique.restitutionCoef + other->m_Physique.restitutionCoef) / 2;

	m_Velocity += newAVelocity * totalRestitutionCoef;
	other->m_Velocity += newBVelocity * totalRestitutionCoef;
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
		float size = m_Radius * 2.f;
		pos.x = m_Position.x + size * anchorX;
		pos.y = m_Position.y + size * anchorY;
	}
	else
	{
		pos.x = m_Position.x + m_Width * anchorX;
		pos.y = m_Position.y + m_Height * anchorX;
	}
	return pos;
}

void Entity::GoToDirection(Vector2f position, float speed)
{
	m_Speed = speed;
	m_Target.TargetPosition = position;

	m_Target.TargetDirection = m_Target.TargetPosition - GetPosition();
	m_Target.TargetDirection.Normalize();

	AddVelocity(m_Target.TargetDirection * speed);
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
		m_Velocity = { 0,0 };
	}

	m_Position += m_Velocity * deltaTime;
}

void Entity::Update(float deltaTime)
{
	Move(deltaTime);
	if (m_EntityType == EntityType::Circle)
		UpdateCollider(GetPosition(), m_Width, m_Height);
	else
		UpdateCollider(GetPosition(0, 0), m_Width, m_Height);
	OnUpdate();
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
		{
			Debug::DrawLine(GetPosition(), m_Target.TargetPosition, Color::Red);
			Debug::DrawCircle(m_Target.TargetPosition, 10.f, Color::Purple);
		}
	}

	Sprite::Draw(w);
}

void Entity::Destroy()
{
	toDestroy = true;
	OnDestroy();
}

Scene* Entity::GetMyScene()
{ { return ApplicationInfo::ActualGame->GetActualScene(); }
}

