#pragma once
#include "Distortion_engine\Entity.h"
class GameIcon : public Entity
{
protected:
	using Entity::Entity;
	std::string m_GameName;
public:
	void SetGameName(std::string GameName) { m_GameName = GameName; }
	std::string GetGameName() { return m_GameName; }
};

