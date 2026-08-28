#include "InputManager.h"
#include <SDL_events.h>

InputManager* InputManager::instance = nullptr;

InputManager* InputManager::Get()
{
	if (instance == nullptr)
	{
		instance = new InputManager;
	}
	return instance;
}

void InputManager::Update(SDL_Event event)
{
	for (auto& key : m_KeysState)
	{
		if (key.second.isDown)
		{
			key.second.isHeld = true;
			key.second.isRelease = false;
		}
		if (key.second.isRelease)
		{
			key.second.isHeld = false;
			key.second.isRelease = false;
		}
	}
	switch (event.type)
	{
	case SDL_KEYDOWN:
	{
		if (m_KeysState[(SDL_GetKeyFromScancode(event.key.keysym.scancode))].isHeld == false)
			m_KeysState[(SDL_GetKeyFromScancode(event.key.keysym.scancode))] = { true, false, false };
		break;
	}
	case SDL_KEYUP:
	{
		m_KeysState[(SDL_GetKeyFromScancode(event.key.keysym.scancode))] = { false, true, false };
		break;
	}
	}
}
