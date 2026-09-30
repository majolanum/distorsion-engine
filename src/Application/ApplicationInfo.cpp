#include "ApplicationInfo.h"
void ApplicationInfo::SetWindowSize(Vector2f* windowSize)
{
	m_WindowWidth = windowSize->x;
	m_WindowHeight = windowSize->y;
}