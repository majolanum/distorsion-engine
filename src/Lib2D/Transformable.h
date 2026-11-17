#pragma once
#include "Vector2f.h"

class Transformable
{
protected:
	Vector2f m_Position;
public:
	Transformable() = default;
	Transformable(float posX, float posY) { m_Position = { posX, posY }; }
};

