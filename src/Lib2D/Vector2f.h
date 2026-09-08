#pragma once
struct Vector2f
{
public:
	float x;
	float y;

	Vector2f(float _x, float _y)
	{
		x = _x; y = _y;
	}

	Vector2f* Normalize();

	friend class DEBUG;
};

