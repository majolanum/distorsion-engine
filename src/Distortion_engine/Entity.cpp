#include <iostream>
#include "Entity.h"

void Entity::GoToDirection(Vector2f position, float speed)
{
	m_Target.IsSet = false;
	if (speed != -1)
	{
		m_Speed = speed;
	}
}

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

void Entity::Repulse()
{

}

void Entity::SetCollider(bool newState, int newType)
{
	CanCollide = newState;
	m_ColliderType = newType;

	if (m_ColliderType == 2)
	{
		if (m_Width < m_Height)
			m_Radius = m_Height;
		else
			m_Radius = m_Width;
	}
}

Vector2f Entity::GetPosition(float anchorX, float anchorY)
{
	Vector2f pos;
	pos.x = m_Position.x + m_Width * anchorX;
	pos.y = m_Position.y + m_Height* anchorX;
	return pos;
}

void Entity::GoToPosition(Vector2f position, float speed)
{
	m_Target.IsSet = false;
	if (speed != -1)
	{
		m_Speed = speed;
		m_Target.TargetPosition = position;

		float targetDirectionX = m_Target.TargetPosition.x - m_Position.x;
		float targetDirectionY = m_Target.TargetPosition.y - m_Position.y;

		m_Target.TargetDirection = { targetDirectionX, targetDirectionY };
		m_Target.TargetDirection.Normalize();

		if (IsAtTarget())
		{
			SetPosition(m_Target.TargetPosition);
			m_Target.IsSet = false;
		}
		else
			m_Target.IsSet = true;
	}
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
		};translation.Normalize();

		m_Position += translation;
		
	}
}

void Entity::Update(float deltaTime)
{
	Move(deltaTime);
	UpdateCollider(m_Position, m_Width, m_Height);
}

void Entity::Draw(Window* w)
{
	Sprite::Draw(w);
}