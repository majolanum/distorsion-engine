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
	Vector2f(int _x, int _y)
	{
		x = static_cast<float>(_x);
		y = static_cast<float>(_y);
	}

	Vector2f& Normalize();
	float Magnitude() const;

	static float Dot(const Vector2f& a, const Vector2f& b);
	static float Distance(const Vector2f& a, const Vector2f& b);
	static float DistanceSqrt(const Vector2f& a, const Vector2f& b);

	Vector2f operator+ (float value) const;
	Vector2f operator- (float value) const;
	Vector2f operator* (float value) const;
	Vector2f operator/ (float value) const;
	Vector2f& operator+= (const float value);
	Vector2f& operator-= (const float value);


	Vector2f operator+ (Vector2f other) const;
	Vector2f operator- (Vector2f other) const;
	Vector2f& operator+= (const Vector2f& other);
	Vector2f& operator-= (const Vector2f& other);

	bool operator== (const Vector2f& other);
	bool operator<= (const Vector2f& other);
	bool operator>= (const Vector2f& other);
	bool operator< (const Vector2f& other);
	bool operator> (const Vector2f& other);
};

