#include "Vector2f.h"
#include <iostream>


float Vector2f::GetDistance(Vector2f* other)
{
	int dx = x - other->x;
	int dy = y - other->y;
	float distance = sqrt(dx * dx + dy * dy);
	return distance;
}

Vector2f* Vector2f::Normalize()
{
	float mag = std::sqrt(x * x + y * y);
	if (mag > 0)
	{
		x /= mag;
		y /= mag;
	}

	return this;
}

Vector2f Vector2f::operator+(float value) const
{
	return { x + value, y + value };
}

Vector2f Vector2f::operator-(float value) const
{
	return { x - value, y - value };
}

Vector2f Vector2f::operator*(float value) const
{
	return { x * value, y * value };
}

Vector2f Vector2f::operator/(float value) const
{
	return { x / value, y / value };
}

Vector2f Vector2f::operator+(Vector2f other) const
{
	return { x + other.x, y + other.y };
}

Vector2f Vector2f::operator-(Vector2f other) const
{
	return{ x - other.x, y - other.y };
}
