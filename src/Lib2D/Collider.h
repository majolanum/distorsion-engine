#pragma once
#include "Vector2f.h"
#include <SDL3/SDL_rect.h>

class Collider
{
private:
	Vector2f m_OwnerPosition = {};
	SDL_FRect m_ColliderPosition = {};
	bool IsCollide(Collider* otherCollider) const;
	bool RectCollide(SDL_FRect otherPosition) const;
	bool CircleRectCollide(SDL_FRect otherPosition) const;
	bool CircleCollide(Vector2f otherPosition, int otherRadius) const;

protected:
	/// <summary>
	/// type 1 : rect, type 2 : circle
	/// </summary>
	int m_ColliderType = 0;
	float m_Radius = 0;

protected:

	Collider() = default;
	void UpdateCollider(Vector2f OwnerPosition, float Width, float Height);

	friend class Scene;
};

