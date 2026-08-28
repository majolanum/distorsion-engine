#include <iostream>

#include "Entity.h"

Entity::Entity(Vector2f* Position, int width, int height, std::string TexturPath) :
	Sprite(TexturPath, Position->x, Position->y)
{
	if (!TexturPath.empty())
	{
		m_Sprite->SetTextureSize(m_Width, m_Height);
	}
	m_Collider = new Collider();
}

void Entity::GoToDirection(Vector2f* position, float speed)
{
	m_Target.IsSet = false;
	if (speed != -1)
	{
		m_Speed = speed;
	}
}

void Entity::GoToPosition(Vector2f* position, float speed)
{
	m_Target.IsSet = false;
	if (speed != -1)
	{
		m_Speed = speed;
		m_Target.TargetPosition = position;

		float targetDirectionX = m_Target.TargetPosition->x - m_Position->x;
		float targetDirectionY = m_Target.TargetPosition->y - m_Position->y;

		m_Target.TargetDirection = new Vector2f(targetDirectionX, targetDirectionY);
		m_Target.TargetDirection->Normalize();

		float distanceToTargetX = m_Target.TargetPosition->x - m_Position->x;
		float distanceToTargetY = m_Target.TargetPosition->y - m_Position->y;

		if (distanceToTargetX < 0.5f || distanceToTargetY < 0.5f)
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
	if (m_Target.IsSet)
	{
		float distance = deltaTime * m_Speed;
		Vector2f* translation = new Vector2f(distance * m_Target.TargetDirection->x, distance * m_Target.TargetDirection->y);

		m_Position->x += translation->x;
		m_Position->y += translation->y;
		std::cout << m_Position->x << " " << m_Position->y << std::endl;
	}

}


void Entity::Update(float deltaTime)
{
	Move(deltaTime);
	m_Collider->UpdateCollider(m_Position, m_Width, m_Height);
}

void Entity::Draw(Window* w)
{
	m_Sprite->Draw(w);
}
