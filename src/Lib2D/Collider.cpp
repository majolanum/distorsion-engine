#include <algorithm>
#include "Collider.h"
#include "Distortion_engine/Entity.h"

void Collider::UpdateCollider(Vector2f ownerPosition, float width, float height)
{
	if (m_ColliderType == ColliderType::Rectangle)
		m_ColliderPosition = { ownerPosition.x - width/2,ownerPosition.y - height / 2,width,height };

	if (m_ColliderType == ColliderType::Circle)
	{
		m_ColliderPosition.x = ownerPosition.x;
		m_ColliderPosition.y = ownerPosition.y;
	}
}

bool Collider::IsCollide(Collider* other) const
{
	switch (m_ColliderType)
	{
	case ColliderType::Rectangle:
	{
		switch (other->m_ColliderType)
		{
		case ColliderType::Rectangle:
			return RectCollide({ other->m_ColliderPosition.x,other->m_ColliderPosition.y });break;

		case ColliderType::Circle:
			return CircleRectCollide({ other->m_ColliderPosition.x,other->m_ColliderPosition.y }, other->m_Radius, m_ColliderPosition);break;
		}
		break;
	}
	case ColliderType::Circle:
	{
		switch (other->m_ColliderType)
		{
		case ColliderType::Rectangle:
			return CircleRectCollide({ m_ColliderPosition.x,m_ColliderPosition.y }, m_Radius, other->m_ColliderPosition);break;

		case ColliderType::Circle:
			return CircleCollide(other->m_ColliderPosition, other->m_Radius); break;
		}
		break;
	}
	}
	return false;
}

bool Collider::RectCollide(SDL_FRect otherPosition) const
{
	return (m_ColliderPosition.x < otherPosition.x + otherPosition.w &&
		m_ColliderPosition.x + m_ColliderPosition.w > otherPosition.x &&
		m_ColliderPosition.y <otherPosition.y + otherPosition.h &&
		m_ColliderPosition.h + m_ColliderPosition.y > otherPosition.y);
}

bool Collider::CircleRectCollide(Vector2f circlePos, float circleRadius, SDL_FRect rect) const
{
	if (circlePos.x > rect.x &&
		circlePos.y > rect.y &&
		circlePos.x < rect.x + rect.w &&
		circlePos.y < rect.y + rect.h)
		return true;
	else
	{
		float rectMaxX = rect.x + rect.w;
		float rectMaxY = rect.y + rect.h;

		float closetX = std::clamp(circlePos.x, rect.x, rectMaxX);
		float closetY = std::clamp(circlePos.y, rect.y, rectMaxY);

		Vector2f closestPoint = { closetX,closetY };
		Vector2f direction = closestPoint - circlePos;
		float distance = direction.Magnitude();

		if (distance < circleRadius)
			return true;
	}
	return false;
}

bool Collider::CircleCollide(SDL_FRect otherPosition, float otherRadius) const
{
	Vector2f otherPos = { otherPosition.x,otherPosition.y };
	Vector2f colliderPos = { m_ColliderPosition.x,m_ColliderPosition.y };

	float distanceSqr = Vector2f::DistanceSqr(colliderPos, otherPos);

	float radiusSqr = (m_Radius + otherRadius) * (m_Radius + otherRadius);

	return distanceSqr < radiusSqr;
}
