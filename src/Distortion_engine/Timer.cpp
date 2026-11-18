#include "Timer.h"

void Timer::StartTimer()
{
	m_Start = 0;
	m_End = 0;
	m_Start = SDL_GetTicksNS();
}

float Timer::EndTimer()
{
	m_End = SDL_GetTicksNS();
	return m_End - m_Start;
}
