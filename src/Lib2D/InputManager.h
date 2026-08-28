#pragma once
#include <SDL.h>
#include <unordered_map>

const enum Key
{
	Key_a = SDLK_a,
	Key_b = SDLK_b,
	Key_c = SDLK_c,
	Key_d = SDLK_d,
	Key_e = SDLK_e,
	Key_f = SDLK_f,
	Key_g = SDLK_g,
	Key_h = SDLK_h,
	Key_i = SDLK_i,
	Key_j = SDLK_j,
	Key_k = SDLK_k,
	Key_l = SDLK_l,
	Key_m = SDLK_m,
	Key_n = SDLK_n,
	Key_o = SDLK_o,
	Key_p = SDLK_p,
	Key_q = SDLK_q,
	Key_r = SDLK_r,
	Key_s = SDLK_s,
	Key_t = SDLK_t,
	Key_u = SDLK_u,
	Key_v = SDLK_v,
	Key_w = SDLK_w,
	Key_x = SDLK_x,
	Key_y = SDLK_y,
	Key_z = SDLK_z,
	Key_echap = SDLK_ESCAPE,
	Key_enter = SDLK_KP_ENTER,

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

public:
	static InputManager* Get();
	void Update(SDL_Event events);
	
	bool IsKeyDown(Key key) { return m_KeysState[SDL_GetKeyFromScancode(SDL_GetScancodeFromKey(key))].isDown; }
	bool IsKeyRelease(Key key) { return m_KeysState[SDL_GetKeyFromScancode(SDL_GetScancodeFromKey(key))].isRelease; }
	bool IsKeyHeld(Key key) { return m_KeysState[SDL_GetKeyFromScancode(SDL_GetScancodeFromKey(key))].isHeld; }
	
};

