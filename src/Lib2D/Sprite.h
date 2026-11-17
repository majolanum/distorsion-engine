#pragma once
#include <iostream>

#include <SDL3_image/SDL_image.h>

#include "Transformable.h"
#include "Drawable.h"

class Window;

class Sprite : public Transformable, public Drawable
{
protected:
	float m_Width = 0.0f;
	float m_Height = 0.0f;
	SDL_Surface* m_Surface = {};
	SDL_Texture* m_Texture = {};

	void ChangeTexturePath(std::string newTexturePath);

public:
	Sprite() : Transformable() {};
	void LoadTexture(const char* TexturePath);
	void SetTextureSize(float newWidth, float newHeight) { m_Width = newWidth; m_Height = newHeight; }
	void Draw(Window*) override;

	Vector2f GetSize() const { return { m_Width,m_Height }; }
	~Sprite();

	friend class Entity;
};


