#pragma once
#include <vector> 

#include "Geometry.h"
#include "Color.h"

class Debug
{
private:
	inline static std::vector<Line> m_AllLine;
	inline static std::vector < Rectangle > m_AllRect;
	inline static std::vector<Circle> m_AllCircle;

	static void Draw(SDL_Renderer* renderer);

public:
	/// <summary>
	/// 
	/// </summary>	
	/// <param name="size">x = width, y = height</param>	
	static void DrawRect(Vector2f position, Vector2f size, Color color, bool filled);
	static void DrawLine(Vector2f pointA, Vector2f pointB, Color color);
	static void DrawCircle(Vector2f center, int radius, Color color);

	friend class Application;
};


