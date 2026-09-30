#pragma once
#include "Vector2f.h"

class Transformable
{
protected:
	Vector2f* m_Position;
public:
	Transformable(float posX, float posY) { m_Position = new Vector2f(posX, posY); }
};

