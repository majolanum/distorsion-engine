#pragma once
#include "Window.h"
#define DEFAULTE_PRECISION 30
#include "SDL3/SDL_pixels.h"
#include "Lib2D/Color.h"

class DEBUG
{
private:
	Window* m_window;
	static DEBUG* instance;


public:
	void SetWindow(Window* window) { m_window = window; }
	static DEBUG* Get();
	void DrawRect(float posX, float posY, float width, float height, SDL_Color color);
	void DrawRect(SDL_FRect rect, SDL_Color color);

	void DrawCircle(int radius, float posX, float posY,SDL_Color Color ,int precision = DEFAULTE_PRECISION);
};


