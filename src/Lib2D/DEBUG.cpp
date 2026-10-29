#include "DEBUG.h"
#include "Vector2f.h"

void Debug::Draw(SDL_Renderer* renderer)
{
	for (Rectangle rect : m_AllRect)
	{
		rect.Draw(renderer);
	}
}

void Debug::DrawRect(Vector2f position, Vector2f size, Color color, bool filled)
{
	Rectangle rect;
	rect.position = position - size/2.0f;
	rect.size = size;
	rect.color = color;
	rect.filled = filled;

	m_AllRect.push_back(rect);
}

void Debug::DrawLine(Vector2f pointA, Vector2f pointB, Color color)
{
	Line line;
	line.pointA = pointA;
	line.pointB = pointB;
	line.color = color;

	m_AllLine.push_back(line);
}

void Debug::DrawCircle(Vector2f center, int radius, Color color)
{
	Circle circle;
	circle.position = center - radius;
	circle.radius = radius;
	circle.color = color;

	m_AllCircle.push_back(circle);
}
