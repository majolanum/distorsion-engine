#include "InputManager.h"
#include <SDL3/SDL_events.h>
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
	case SDL_EVENT_KEY_DOWN:
	{
		if (m_KeysState[(SDL_GetKeyFromScancode(event.key.scancode, SDL_KMOD_NONE, true))].isHeld == false)
			m_KeysState[(SDL_GetKeyFromScancode(event.key.scancode, SDL_KMOD_NONE, true))] = { true, false, false };
		break;
	}
	case SDL_EVENT_KEY_UP:
	{
		m_KeysState[(SDL_GetKeyFromScancode(event.key.scancode, SDL_KMOD_NONE, true))] = { false, true, false };
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
	case SDL_EVENT_MOUSE_BUTTON_DOWN:
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
	case SDL_EVENT_MOUSE_BUTTON_UP:
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
	case SDL_EVENT_MOUSE_MOTION:
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
