#pragma once
struct Vector2f
{
protected:
	float m_x;
	float m_y;

public:
	Vector2f(float x, float y) : m_x(x), m_y(y) {}
	void Set(float x, float y) { m_x = x; m_y = y; }

	Vector2f GetVector() const { return { m_x,m_y }; }

	float GetPosX() { return m_x; }
	float GetPosY() { return m_y; }

	friend class DEBUG;
};

