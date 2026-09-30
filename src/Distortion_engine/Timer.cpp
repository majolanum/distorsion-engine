#include "Timer.h"

void Timer::StartTimer()
{
	m_Start = 0;
	m_End = 0;
	m_Start = SDL_GetTicks();
}

float Timer::EndTimer()
{
	m_End = SDL_GetTicks();
	return m_End - m_Start;
}
