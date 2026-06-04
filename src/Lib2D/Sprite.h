#pragma once
#include <iostream>

#include "SDL_image.h"

#include "Transformable.h"
#include "Drawable.h"

class Window;

class Sprite : public Transformable, public Drawable
{
protected:
	int m_Width;
	int m_Height;
	SDL_Surface* m_Surface;
	SDL_Texture* m_Texture;

	void ChangeTexturePath(std::string newTexturePath);
		
public:
	Sprite(std::string texturePath,float posX = 0, float posY = 0);
	void LoadTexture(const char* TexturePath);
	void SetTextureSize(int newWidth, int newHeight) { m_Width = newWidth; m_Height = newHeight; }
	void Draw(Window*) override;

	~Sprite();
};


