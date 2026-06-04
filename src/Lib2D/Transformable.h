#pragma once
#include "Vector2f.h"

class Transformable
{
protected:
	Vector2f* Position;
public:
	Transformable(float posX, float posY) { Position = new Vector2f(posX, posY); }
};

