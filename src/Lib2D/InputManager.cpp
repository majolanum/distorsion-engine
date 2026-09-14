#include "InputManager.h"
#include <SDL_events.h>
#include <iostream>

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
	UpdateMouse(event);
}

void InputManager::UpdateMouse(SDL_Event event)
{
	for (auto& key : m_MouseState)
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
	case SDL_MOUSEBUTTONDOWN:
	{
		switch (event.button.button)
		{
		case 1:
		{
			if (m_MouseState[Mouse_Left].isHeld == false)
				m_MouseState[Mouse_Left] = { true, false, false };
			break;
		}
		case 2:
		{
			if (m_MouseState[Mouse_Middle].isHeld == false)
				m_MouseState[Mouse_Middle] = { true, false, false };
			break;
		}
		case 3:
		{
			if (m_MouseState[Mouse_Right].isHeld == false)
				m_MouseState[Mouse_Right] = { true, false, false };
			break;
		}
		}
		break;
	}
	case SDL_MOUSEBUTTONUP:
	{
		switch (event.button.button)
		{
		case 1:
		{
			m_MouseState[Mouse_Left] = { false, true, false };
			break;
		}
		case 2:
		{
			m_MouseState[Mouse_Middle] = { false, true, false };
			break;
		}
		case 3:
		{
			m_MouseState[Mouse_Right] = { false, true, false };
			break;
		}
		}
		break;

	}
	case SDL_MOUSEMOTION:
	{
		if (MousePos == nullptr)
			MousePos = new Vector2f(event.button.x, event.button.y);
		else
		{
			MousePos->x = event.button.x;
			MousePos->y = event.button.y;
		}
		break;
	}
	}
}
