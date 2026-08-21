#include "Entity.h"
Entity::Entity(int positionX, int positionY, std::string TexturPath = NULL) : Transformable(positionX, positionY)
{
	if (!TexturPath.empty())
	{
		m_Sprite = new Sprite(TexturPath, positionX, positionY);
		m_Sprite->SetTextureSize(200, 200);
	}

	m_Collider = new Collider();
}

void Entity::Update(float deltaTime)
{	
	m_Collider->UpdateCollider(m_Position, m_Sprite->GetWidth(), m_Sprite->GetWidth());
}

void Entity::Draw(Window*w)
{
	m_Sprite->Draw(w);
}
