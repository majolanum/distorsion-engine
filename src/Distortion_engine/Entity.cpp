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

	//TODO : a enlever a la fin des test
	m_Speed = 10;
}

void Entity::Move(Vector2f* motion)
{
	Vector2f NormMotion = motion->Normalize();
	
	m_Position->x += NormMotion.x * m_Speed;
	m_Position->y += NormMotion.y * m_Speed;

	std::cout << m_Position->x << " " << m_Position->y << std::endl;
}

void Entity::Update(float deltaTime)
{
	m_Collider->UpdateCollider(m_Position, m_Width, m_Height);
}

void Entity::Draw(Window* w)
{
	Sprite::Draw(w);
}
