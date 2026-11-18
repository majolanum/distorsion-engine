#include "Timer.h"

void Timer::StartTimer()
{	
	m_Start = SDL_GetTicksNS();
	m_End = SDL_GetTicksNS();
}

Uint64 Timer::EndTimer()
{
	m_End = SDL_GetTicksNS();
	return m_End - m_Start;
}
