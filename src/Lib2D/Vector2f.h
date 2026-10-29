#pragma once
struct Vector2f
{
public:
	float x;
	float y;
	Vector2f() = default;
	Vector2f(float _x, float _y)
	{
		x = _x; y = _y;
	}

	float GetDistance(Vector2f* other);
	Vector2f* Normalize();

	Vector2f operator+ (float value) const;
	Vector2f operator- (float value) const;
	Vector2f operator* (float value) const;
	Vector2f operator/ (float value) const;

	Vector2f operator+ (Vector2f other) const;
	Vector2f operator- (Vector2f other) const;
};

