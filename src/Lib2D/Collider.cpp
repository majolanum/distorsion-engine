#include "Collider.h"

void Collider::UpdateCollider(Vector2f* OwnerPosition, int Width, int Height)
{
	m_Position = { (int)OwnerPosition->GetPosX(), (int)OwnerPosition->GetPosY(),Width,Height };
}
