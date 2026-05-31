#pragma once
#include "SDL_image.h"

#include "Transformable.h"
#include "Drawable.h"

class Window;

class Sprite : public Transformable, public Drawable
{
protected:
	std::string m_TexturePath;

	float m_Width;
	float m_Height;
	
	SDL_Rect* destinationRect;

	void ChangeTexturePath(std::string newTexturePath) 
	{ m_TexturePath = newTexturePath; }
public:
	Sprite(float width, float height, std::string texturePath);
	void Draw(Window*) override;
};

