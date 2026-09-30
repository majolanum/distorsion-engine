#include <iostream>
#include "Collider.h"

void Collider::UpdateCollider(Vector2f* OwnerPosition, int Width, int Height)
{
	m_ColliderPosition = { (int)OwnerPosition->x, (int)OwnerPosition->y,Width,Height };
	if (ColliderType == 2)
	{
		if (Width < Height)
			Radius = Height;
		else
			Radius = Width;
	}
}

bool Collider::IsCollide(Collider* otherCollider)
{
	switch (ColliderType)
	{
	case 1:
	{
		switch (otherCollider->ColliderType)
		{
		case 1:
		{
			return RectCollide(otherCollider->m_ColliderPosition);
			break;
		}
		case 2:
		{
			return CircleRectCollide(otherCollider->m_ColliderPosition);
			break;
		}
		}
		break;
	}
	case 2:
	{
		switch (otherCollider->ColliderType)
		{
		case 1:
		{
			return CircleRectCollide(otherCollider->m_ColliderPosition);
			break;
		}
		case 2:
		{
			return CircleCollide(otherCollider->m_ColliderPosition,otherCollider->Radius);
			break;
		}
		}
		break;
	}
	}
}

bool Collider::RectCollide(SDL_Rect otherPosition)
{
	if (m_ColliderPosition.x < otherPosition.x + otherPosition.w &&
		m_ColliderPosition.x + m_ColliderPosition.w > otherPosition.x &&
		m_ColliderPosition.y <otherPosition.y + otherPosition.h &&
		m_ColliderPosition.h + m_ColliderPosition.y > otherPosition.y)
		return true;
	else
		return false;
}

bool Collider::CircleRectCollide(SDL_Rect otherPosition)
{
	return false;
}

bool Collider::CircleCollide(SDL_Rect otherPosition, int otherRadius)
{
	float distance = m_OwnerPosition->GetDistance(new Vector2f(otherPosition.x, otherPosition.y));
	if (distance < Radius + otherRadius)
		return true;
	else
		return false;
}
