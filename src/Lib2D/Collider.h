#pragma once
#include "Vector2f.h"
#include <SDL3/SDL_rect.h>

class Collider
{
private:
	Vector2f* m_OwnerPosition;
	SDL_Rect m_ColliderPosition;

	/// <summary>
	/// type 1 : rect, type 2 : circle
	/// </summary>
	int m_ColliderType;
	int m_Radius;

	bool IsCollide(Collider* otherCollider);
	bool RectCollide(SDL_Rect otherPosition);
	bool CircleRectCollide(SDL_Rect otherPosition);
	bool CircleCollide(SDL_Rect otherPosition, int otherRadius);

protected:
	Collider(int colliderType) :m_ColliderType(colliderType) {}
	void SetColliderType(int newColliderType) { m_ColliderType = newColliderType; }
	void UpdateCollider(Vector2f* OwnerPosition, int Width, int Height);

	friend class Scene;
};

