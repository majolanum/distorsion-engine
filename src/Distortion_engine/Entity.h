#pragma once
#include <string>

#include "Lib2D/Sprite.h"
#include "Lib2D/Collider.h"

class Entity : public Sprite, public Collider
{
	struct Target
	{
		Vector2f* TargetPosition = nullptr;
		Vector2f* TargetDirection = nullptr;
		bool IsSet = false;
	};
	Target m_Target;

private:	
	int m_Speed = 0;
	bool ToDestroy= false;
	bool CanCollide; 
	int m_Index = 0;

	void Move(float deltaTime);
	void Update(float deltaTime);
	void Draw(Window*) override;
	bool IsAtTarget();

protected:
	Entity(Vector2f* Position, int width, int height, std::string TexturPath, bool canCollide, int colliderType);
	
	virtual void OnInitialize() {}
	virtual void OnUpdate() {}
	virtual void OnDestroy() {}

	void SetIndex(int index) { m_Index = index; }
	int GetIndex() const { return m_Index; }

public:
	void SetPosition(Vector2f* Position) { m_Position = Position; }
	void GoToPosition(Vector2f* Position, float speed = -1);

	void GoToDirection(Vector2f* position, float speed = -1);

	friend class Collider;
	friend class Scene;
};
