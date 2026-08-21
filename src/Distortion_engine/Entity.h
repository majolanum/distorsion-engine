#pragma once
#include "Lib2D/Sprite.h"
#include "Lib2D/Collider.h"

class Entity : public Transformable
{
private :
	Sprite* m_Sprite;	
	Collider* m_Collider;

protected:
	int m_Index;

	friend class Collider;
};

