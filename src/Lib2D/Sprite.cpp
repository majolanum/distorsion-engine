#include "Sprite.h"

Sprite::Sprite(float width, float height, std::string texturePath)
{
	m_Width = width; m_Height = height;
	m_TexturePath = texturePath;
}

void Sprite::Draw(Window* w)
{
	SDL_RenderCopy()
}
