#include "Vector2f.h"
#include <iostream>


Vector2f Vector2f::Normalize()
{
	float mag = std::sqrt(x * x + y * y);
	if (mag > 0)
	{
		x /= mag;
		y /= mag;
	}

	return *this;
}
