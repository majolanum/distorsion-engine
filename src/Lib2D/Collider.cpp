#include <iostream>
#include "Collider.h"
#include "Distortion_engine/Entity.h"

void Collider::UpdateCollider(Vector2f ownerPosition, float width, float height)
{
	if (m_ColliderType == ColliderType::Rectangle)
		m_ColliderPosition = { ownerPosition.x,ownerPosition.y,width,height };

	if (m_ColliderType == ColliderType::Circle)
	{
		m_ColliderPosition.x = ownerPosition.x;
		m_ColliderPosition.y = ownerPosition.y;
	}
}

bool Collider::IsCollide(Collider* otherCollider) const
{
	switch (m_ColliderType)
	{
	case ColliderType::Rectangle:
	{
		switch (otherCollider->m_ColliderType)
		{
		case ColliderType::Rectangle:
			return RectCollide({ otherCollider->m_ColliderPosition.x,otherCollider->m_ColliderPosition.y });break;

		case ColliderType::Circle:
			return CircleRectCollide({ otherCollider->m_ColliderPosition.x,otherCollider->m_ColliderPosition.y });break;
		}
		break;
	}
	case ColliderType::Circle:
	{
		switch (otherCollider->m_ColliderType)
		{
		case ColliderType::Rectangle:
			return CircleRectCollide({ otherCollider->m_ColliderPosition.x,otherCollider->m_ColliderPosition.y });break;

		case ColliderType::Circle:
			return CircleCollide(otherCollider->m_ColliderPosition, otherCollider->m_Radius); break;
		}
		break;
	}
	}
	return false;
}

bool Collider::RectCollide(SDL_FRect otherPosition) const
{
	if (m_ColliderPosition.x < otherPosition.x + otherPosition.w &&
		m_ColliderPosition.x + m_ColliderPosition.w > otherPosition.x &&
		m_ColliderPosition.y <otherPosition.y + otherPosition.h &&
		m_ColliderPosition.h + m_ColliderPosition.y > otherPosition.y)
		return true;
	else
		return false;
}

bool Collider::CircleRectCollide(SDL_FRect otherPosition) const
{
	return false;
}

bool Collider::CircleCollide(SDL_FRect otherPosition, int otherRadius) const
{
	Vector2f otherPos = { otherPosition.x,otherPosition.y };
	Vector2f colliderPos = { m_ColliderPosition.x,m_ColliderPosition.y };

	float distance = Vector2f::Distance(colliderPos, otherPos);

	if (distance < m_Radius + otherRadius)
		return true;
	else
		return false;
}
