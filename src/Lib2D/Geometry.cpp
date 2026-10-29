#include "Geometry.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <SDL3/SDL_render.h>
#include <SDL3/SDL_rect.h>


void Circle::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	//if (filled)
	//	DrawFilled(renderer);
	//else
		DrawUnfilled(renderer);

}

void Circle::DrawUnfilled(SDL_Renderer* renderer)
{
	Vector2f center = position + radius;
	
	constexpr int segments = 64;
	SDL_FPoint points[segments + 1];

	for (int i = 1; i <= segments; i++)
	{
		float angle = i * 2.0f * M_PI/ segments;
		
		points[i].x = center.x + cos(angle) * radius;
		points[i].y = center.y + sin(angle) * radius;
		
	}
	SDL_RenderLines(renderer, points,segments+1);
}

void Circle::DrawFilled(SDL_Renderer* renderer)
{
}


void Rectangle::Draw(SDL_Renderer* renderer)
{
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
	SDL_FRect rect = { position.x,position.y,size.x,size.y };
	if (filled)
		SDL_RenderFillRect(renderer, &rect);
	else
		SDL_RenderRect(renderer, &rect);

}

void Line::Draw(SDL_Renderer* renderer)
{
}
