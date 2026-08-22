#include "DEBUG.h"
#include "Vector2f.h"

DEBUG* DEBUG::instance = nullptr;

DEBUG* DEBUG::Get()
{
	if (instance == nullptr)
		instance = new DEBUG();
	return instance;
}

void DEBUG::DrawRect(SDL_Rect rect, SDL_Color color)
{
	DrawRect(rect.x, rect.y, rect.w, rect.h, color);
}

void DEBUG::DrawRect(float posX, float posY, float width, float height, SDL_Color color)
{
	SDL_Renderer* renderer = m_window->m_Renderer;
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	SDL_RenderDrawLine(renderer, posX, posY, posX + width, posY);
	SDL_RenderDrawLine(renderer, posX, posY + height, posX + width, posY + height);
	SDL_RenderDrawLine(renderer, posX, posY, posX, posY + height);
	SDL_RenderDrawLine(renderer, posX + width, posY, posX + width, posY + height);
}

void DEBUG::DrawCircle(int radius, float posX, float posY, SDL_Color color, int precision)
{
	float distanceBetweenTwoPoints = (2.0f * M_PI) / precision;
	SDL_SetRenderDrawColor(m_window->m_Renderer, color.r, color.g, color.b, color.a);
	Vector2f center = { posX, posY };

	int x1 = center.x+ radius * cos(0);
	int y1 = center.y + radius * sin(0);

	for (int i = 1; i <= precision; i++)
	{
		float x2 = center.x + radius * cos(i * distanceBetweenTwoPoints);
		float y2 = center.y + radius * sin(i * distanceBetweenTwoPoints);

		SDL_RenderDrawLine(m_window->m_Renderer, x1, y1, x2, y2);
		
		x1 = x2;
		y1 = y2;
	}
}


