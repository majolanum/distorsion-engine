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
	
	int m_Speed = 0;
	bool ToDestroy= false;

	void Move(float deltaTime);

protected:
	int m_Index = 0;
	
	virtual void OnInitialize();
	virtual void OnUpdate();
	virtual void OnDestroy();

	void SetIndex(int index) { m_Index = index; }

	void SetPosition(Vector2f* Position) { m_Position = Position; }

	int GetIndex() const { return m_Index; }

public:
	Entity(Vector2f* Position, int width, int height, std::string TexturPath);

	
	//TODO : a déplacer a la fin des test
	void Draw(Window*) override;
	void GoToDirection(Vector2f* position, float speed = -1);
	bool IsAtTarget();
	void GoToPosition(Vector2f* Position, float speed = -1);
	void Update(float deltaTime);

	~Entity();

	friend class Collider;
	friend class Scene;
};
