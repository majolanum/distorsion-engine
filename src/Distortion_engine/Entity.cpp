#include <iostream>

#include "Entity.h"

Entity::Entity(Vector2f* Position, std::string TexturPath) :
	Sprite(TexturPath, Position->x, Position->y)
{
	if (!TexturPath.empty())
	{
		SetTextureSize(200, 200);
	}

	m_Collider = new Collider();
}

void Entity::GoToDirection(Vector2f* position, float speed)
{
	target.IsSet = false;
	if (speed != -1)
	{ 
		
	}
}

void Entity::GoToPosition(Vector2f* position, float speed)
{
	target.IsSet = false;
	if (speed != -1)
	{
		target.TargetPosition = position;
		
		target.IsSet = true;
	}
}

void Entity::Move(float deltaTime)
{
	m_Position->x += target.TargetDirection->x * deltaTime;
	m_Position->y += target.TargetDirection->y * deltaTime;

	std::cout << m_Position->x << " " << m_Position->y << std::endl;
}

void Entity::Update(float deltaTime)
{

	float distance = deltaTime * m_Speed;
	Vector2f translation = distance * mDirection;
	mShape.move(translation);

	Move(deltaTime);
	m_Collider->UpdateCollider(m_Position, m_Width, m_Height);
}

void Entity::Draw(Window* w)
{
	Sprite::Draw(w);
}
