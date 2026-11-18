#pragma once
#include "Vector2f.h"
#include <SDL3/SDL_rect.h>

enum class ColliderType
{
	Non = 0,
	Rectangle = 1,
	Circle = 2,
};

class Collider
{
private:
	SDL_FRect m_ColliderPosition = {};
	bool IsCollide(Collider* otherCollider) const;
	bool RectCollide(SDL_FRect otherPosition) const;
	bool CircleRectCollide(SDL_FRect otherPosition) const;
	bool CircleCollide(SDL_FRect otherPosition, int otherRadius) const;

protected:
	/// <summary>
	/// type 1 : rect, type 2 : circle
	/// </summary>
	ColliderType m_ColliderType = ColliderType::Non;
	float m_Radius = 0.f;

	Collider() = default;
	void UpdateCollider(Vector2f ownerPosition, float width, float height);

	friend class Scene;
};

