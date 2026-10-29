#pragma once
#include "Vector2f.h"
#include "Color.h"

struct SDL_Renderer;

struct Geometry
{
	Color color = Color::White;
	bool filled = false;

	virtual void Draw(SDL_Renderer* renderer) = 0;
};

struct Line :public Geometry
{
	Vector2f pointA;
	Vector2f pointB;

	void Draw(SDL_Renderer* renderer) override;
};

struct Circle :public  Geometry
{
	Vector2f position;
	float radius = 0.0f;

	void Draw(SDL_Renderer* renderer) override;
private:
	void DrawUnfilled(SDL_Renderer* renderer);
	void DrawFilled(SDL_Renderer* renderer);

};

struct Rectangle :public  Geometry
{
	Vector2f position;
	Vector2f size;

	void Draw(SDL_Renderer* renderer) override;
};