#pragma once
#include "Lib2D/Vector2f.h"
#include <string>

class ApplicationInfo
{
private:
	static inline float m_DeltaTime = 0.0f;
	static inline float m_WindowWidth = 0, m_WindowHeight = 0;
	static void SetDeltaTime(float deltaTime) { m_DeltaTime = deltaTime; }
	static void SetWindowSize(Vector2f* windowSize);

public:
	static float GetDeltaTime() { return m_DeltaTime; }
	static float GetWindowWidth() { return m_WindowWidth; }
	static float GetWindowHeight() { return m_WindowHeight; }
	static std::string GetTemplateLink() { return ("../../res/Lib2D/PlaceHolder.png"); }

	friend class Application;
};

