#pragma once
#include <string>

#include "Lib2D/Sprite.h"
#include "Lib2D/Collider.h"

class Entity : public Sprite
{
	struct Target
	{
		Vector2f* TargetPosition = nullptr;
		Vector2f* TargetDirection = nullptr;
		bool IsSet = false;
	};
	Target m_Target;

private:
	Collider* m_Collider;
	Sprite* m_Sprite;

	int m_Speed = 0;

	void Move(float deltaTime);

protected:
	int m_Index = 0;

	void SetIndex(int index) { m_Index = index; }

	void SetPosition(Vector2f* Position) { m_Position = Position; }

	int GetIndex() const { return m_Index; }

public:
	Entity(Vector2f* Position, int width, int height, std::string TexturPath = NULL);

	friend class Collider;

	//TODO : a déplacer a la fin des test
	void Draw(Window*);
	void GoToDirection(Vector2f* position, float speed = -1);
	void GoToPosition(Vector2f* Position, float speed = -1);
	void Update(float deltaTime);
};
