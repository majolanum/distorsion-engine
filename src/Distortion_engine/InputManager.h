#pragma once
#include <SDL3/SDL.h>
#include <unordered_map>

#include "Lib2D/Vector2f.h"

const enum Key
{
	Key_a = SDLK_A,
	Key_b = SDLK_B,
	Key_c = SDLK_C,
	Key_D = SDLK_D,
	Key_e = SDLK_E,
	Key_f = SDLK_F,
	Key_g = SDLK_G,
	Key_h = SDLK_H,
	Key_i = SDLK_I,
	Key_j = SDLK_J,
	Key_k = SDLK_K,
	Key_l = SDLK_L,
	Key_m = SDLK_M,
	Key_n = SDLK_N,
	Key_o = SDLK_O,
	Key_p = SDLK_P,
	Key_q = SDLK_Q,
	Key_r = SDLK_R,
	Key_s = SDLK_S,
	Key_t = SDLK_T,
	Key_u = SDLK_U,
	Key_v = SDLK_V,
	Key_w = SDLK_W,
	Key_x = SDLK_X,
	Key_y = SDLK_Y,
	Key_z = SDLK_Z,
	Key_echap = SDLK_ESCAPE,
	Key_enter = SDLK_KP_ENTER,

};

const enum Mouse
{
	Mouse_Left = SDL_BUTTON_LEFT,
	Mouse_Middle = SDL_BUTTON_MIDDLE,
	Mouse_Right = SDL_BUTTON_RIGHT,
};

class InputManager
{
	struct KeyState
	{
		bool isDown;
		bool isRelease;
		bool isHeld;
	};

private:
	InputManager() {}
	static InputManager* instance;

	std::unordered_map<SDL_Keycode, KeyState> m_KeysState;
	std::unordered_map<Mouse, KeyState> m_MouseState;

	Vector2f* MousePos = new Vector2f(0,0);

public:
	static InputManager* Get();
	void Update(SDL_Event events);

	//partie clavier
	bool IsKeyDown(Key key) { return m_KeysState[SDL_GetKeyFromScancode(SDL_GetScancodeFromKey(key,NULL),SDL_KMOD_NONE,true)].isDown; }
	bool IsKeyRelease(Key key) { return m_KeysState[SDL_GetKeyFromScancode(SDL_GetScancodeFromKey(key, NULL), SDL_KMOD_NONE, true)].isRelease; }
	bool IsKeyHeld(Key key) { return m_KeysState[SDL_GetKeyFromScancode(SDL_GetScancodeFromKey(key, NULL), SDL_KMOD_NONE, true)].isHeld; }

	//partie souris
	void UpdateMouse(SDL_Event events);
	bool IsKeyDown(Mouse key) { return m_MouseState[key].isDown; }
	bool IsKeyRelease(Mouse key) { return m_MouseState[key].isRelease; }
	bool IsKeyHeld(Mouse key) { return m_MouseState[key].isHeld; }

	Vector2f* GetMousePosition() { return MousePos; }
};

