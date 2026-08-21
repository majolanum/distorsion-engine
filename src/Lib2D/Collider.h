#pragma once
#include "Vector2f.h"
#include "SDL_rect.h"

class Collider
{
private:
	Vector2f* m_OwnerPosition;
	SDL_Rect m_Position;

public:
	
	void UpdateCollider(Vector2f* OwnerPosition, int Width, int Height);

	bool IsCollide(Collider* otherCollider);

	SDL_Rect getpos() { return m_Position; }
};

