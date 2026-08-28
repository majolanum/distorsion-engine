#pragma once
#include "SDL_timer.h"

class Timer
{
private:
	Uint64 m_Start = 0, m_End =0;

public:
	void StartTimer();
	float EndTimer();
};

