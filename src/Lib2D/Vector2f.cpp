#include "Vector2f.h"
#include <iostream>
#include <cmath>

Vector2f& Vector2f::Normalize()
{
	float mag = std::sqrt(x * x + y * y);
	if (mag > 0)
	{
		x /= mag;
		y /= mag;
	}

	return *this;
}

float Vector2f::Dot(const Vector2f& a, const Vector2f& b)
{
	return a.x * b.x + a.y * b.y;
}

float Vector2f::Distance(const Vector2f& a, const Vector2f& b)
{
	return (b - a).Magnitude();
}

float Vector2f::DistanceSqr(const Vector2f& a, const Vector2f& b)
{
	Vector2f translation = b - a;
	return Dot(translation,translation);
}

float Vector2f::Magnitude() const
{
	return std::hypot(x, y);
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

Vector2f& Vector2f::operator+=(const float value)
{
	x += value;
	y += value;
	return *this;
}

Vector2f& Vector2f::operator-=(const float value)
{
	x -= value;
	y -= value;
	return *this;
}



Vector2f Vector2f::operator+(Vector2f other) const
{
	return { x + other.x, y + other.y };
}

Vector2f Vector2f::operator-(Vector2f other) const
{
	return{ x - other.x, y - other.y };
}

Vector2f Vector2f::operator*(Vector2f other) const
{
	return { x * other.x, y * other.y };
}

Vector2f Vector2f::operator/(Vector2f other) const
{
	return { x / other.x, y / other.y };
}

Vector2f& Vector2f::operator+=(const Vector2f& other)
{
	x += other.x;
	y += other.y;

	return *this;
}

Vector2f& Vector2f::operator-=(const Vector2f& other)
{
	x -= other.x;
	y -= other.y;

	return *this;
}

bool Vector2f::operator==(const Vector2f& other)
{
	return x == other.x && y == other.y;
}

bool Vector2f::operator<=(const Vector2f& other)
{
	return x <= other.x && y <= other.y;
}

bool Vector2f::operator>=(const Vector2f& other)
{
	return x >= other.x && y >= other.y;
}

bool Vector2f::operator<(const Vector2f& other)
{
	return x < other.x && y < other.y;
}

bool Vector2f::operator>(const Vector2f& other)
{
	return x > other.x && y > other.y;
}
