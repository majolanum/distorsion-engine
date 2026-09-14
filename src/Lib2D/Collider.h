#pragma once
#include "Vector2f.h"
#include "SDL_rect.h"

class Collider
{
private:
	Vector2f* m_OwnerPosition;
	SDL_Rect m_ColliderPosition;

	/// <summary>
	/// type 1 : rect, type 2 : circle
	/// </summary>
	int ColliderType;
	int Radius;

	bool IsCollide(Collider* otherCollider);
	bool RectCollide(SDL_Rect otherPosition);
	bool CircleRectCollide(SDL_Rect otherPosition);
	bool CircleCollide(SDL_Rect otherPosition, int otherRadius);

protected:
	Collider(int colliderType) :ColliderType(colliderType) {}
	void UpdateCollider(Vector2f* OwnerPosition, int Width, int Height);

	friend class Scene;
};

