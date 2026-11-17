#include <iostream>
#include "Collider.h"

void Collider::UpdateCollider(Vector2f OwnerPosition, float Width, float Height)
{
	m_ColliderPosition = { OwnerPosition.x, OwnerPosition.y,Width,Height };
}

bool Collider::IsCollide(Collider* otherCollider) const
{
	switch (m_ColliderType)
	{
	case 1:
	{
		switch (otherCollider->m_ColliderType)
		{
		case 1:
		{
			return RectCollide({ otherCollider->m_ColliderPosition.x,otherCollider->m_ColliderPosition.y });
			break;
		}
		case 2:
		{
			return CircleRectCollide({ otherCollider->m_ColliderPosition.x,otherCollider->m_ColliderPosition.y });
			break;
		}
		}
		break;
	}
	case 2:
	{
		switch (otherCollider->m_ColliderType)
		{
		case 1:
		{
			return CircleRectCollide({ otherCollider->m_ColliderPosition.x,otherCollider->m_ColliderPosition.y });
			break;
		}
		case 2:
		{
			return CircleCollide({ otherCollider->m_ColliderPosition.x,otherCollider->m_ColliderPosition.y }, otherCollider->m_Radius);
			break;
		}
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

bool Collider::CircleCollide(Vector2f otherPosition, int otherRadius) const
{
	float distance = m_OwnerPosition.Distance(m_OwnerPosition, otherPosition);
	if (distance < m_Radius + otherRadius)
		return true;
	else
		return false;
}
