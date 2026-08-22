#pragma once
#include <string>

#include "Lib2D/Sprite.h"
#include "Lib2D/Collider.h"

class Entity : public Sprite
{
private:
	Collider* m_Collider;
	float m_Speed;
	void Update(float deltaTime);

protected:
	int m_Index;
	void SetSpeed(float speed) { m_Speed = speed; }
	

public:
	Entity(Vector2f* Position, std::string TexturPath = NULL);
	
	friend class Collider;
	//TODO : a déplacer a la fin des test
	void Move(Vector2f* motion);
	void Draw(Window*);
};
