#pragma once
#include <SDL.h>
#include <unordered_map>

const enum Key
{
	a = SDLK_a,
	b = SDLK_b,
	c = SDLK_c,
	d = SDLK_d,
	e = SDLK_e,
	f = SDLK_f,
	g = SDLK_g,
	h = SDLK_h,
	i = SDLK_i,
	j = SDLK_j,
	k = SDLK_k,
	l = SDLK_l,
	m = SDLK_m,
	n = SDLK_n,
	o = SDLK_o,
	p = SDLK_p,
	q = SDLK_q,
	r = SDLK_r,
	s = SDLK_s,
	t = SDLK_t,
	u = SDLK_u,
	v = SDLK_v,
	w = SDLK_w,
	x = SDLK_x,
	y = SDLK_y,
	z = SDLK_z,
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
	
	std::unordered_map<SDL_Keycode, KeyState> gett() { return m_KeysState; }
};

