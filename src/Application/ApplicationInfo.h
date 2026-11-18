#pragma once
#include "Lib2D/Vector2f.h"
#include <string>
#include <SDL3/SDl_Timer.h>

class ApplicationInfo
{
private:
	static inline float m_DeltaTime = 0.0f;
	static inline float m_WindowWidth = 0, m_WindowHeight = 0;
	static void SetDeltaTime(Uint64 deltaTimeNS) { m_DeltaTime = static_cast<float>(deltaTimeNS) / 1000000000.f;  }
	static void SetWindowSize(Vector2f windowSize);

public:
	static inline bool IsDebugDraw = false;

	static float GetDeltaTime() { return m_DeltaTime; }
	static float GetWindowWidth() { return m_WindowWidth; }
	static float GetWindowHeight() { return m_WindowHeight; }
	static const std::string GetTemplateLink() { return "../../res/Lib2D/PlaceHolder.png"; }

	friend class Application;
};

