#pragma once
#include <SDL_render.h>
#include <SDL_video.h>

#include <iostream>

struct Drawable;

class Window
{
protected:

	SDL_Window* m_MainWindow;
	SDL_Renderer* m_Renderer;

	bool isWindowOpen;

public:
	void OpenWindow(const char* windowName="Distortion engine");

	void ClearWindow();

	void Draw(Drawable* d);
	void Present() { SDL_RenderPresent(m_Renderer); };

	bool IsWindowOpen() { return isWindowOpen; }

	~Window();
	friend class Sprite;
	friend class DEBUG;
};

