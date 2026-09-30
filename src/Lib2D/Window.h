#pragma once
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>

#include <iostream>

#include "Vector2f.h"

struct Drawable;

class Window
{
protected:

	SDL_Window* m_MainWindow;
	SDL_Renderer* m_Renderer;

	bool isWindowOpen;

public:
	Vector2f* OpenWindow(const char* windowName = "Distortion engine", float Width = 1000, float Height = 500);

	void ClearWindow();

	void Draw(Drawable* d);
	void Present() { SDL_RenderPresent(m_Renderer); };

	bool IsWindowOpen() { return isWindowOpen; }

	~Window();
	friend class Sprite;
	friend class AssetManager;
	friend class DEBUG;
};

