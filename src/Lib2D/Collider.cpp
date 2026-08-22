#include "Collider.h"

void Collider::UpdateCollider(Vector2f* OwnerPosition, int Width, int Height)
{
	m_Position = { (int)OwnerPosition->x, (int)OwnerPosition->y,Width,Height };
}
