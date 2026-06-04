#include "Sprite.h"

Sprite::Sprite(std::string texturePath, float posX, float posY) : Transformable(posX, posY)
{
	LoadTexture(texturePath.c_str());
}

void Sprite::LoadTexture(const char* TexturePath)
{
	if (m_Texture) {
		SDL_DestroyTexture(m_Texture);
		m_Texture = nullptr;
	}

	if (m_Surface) {
		SDL_FreeSurface(m_Surface);
		m_Surface = nullptr;
	}

	m_Surface = IMG_Load(TexturePath);
	if (m_Surface == nullptr)
	{
		std::cout << "erreure de chargement de la surface" << std::endl;
		exit(1);
	}

}

void Sprite::Draw(Window* w)
{
	if (m_Texture == nullptr)
	{
		m_Texture = SDL_CreateTextureFromSurface(w->m_Renderer, m_Surface);
		SDL_FreeSurface(m_Surface); m_Surface = nullptr;
		SDL_QueryTexture(m_Texture, NULL, NULL, &m_Width, &m_Height);
	}

	SDL_Rect dst = { Position->GetPosX(), Position->GetPosY(), m_Width,m_Height };
	SDL_RenderCopy(w->m_Renderer, m_Texture, NULL, &dst);
		std::cout << SDL_GetError();

}

Sprite::~Sprite()
{
}
