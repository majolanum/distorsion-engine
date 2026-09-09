#include "Window.h"
#include <SDL.h>
#include "Drawable.h"

void Window::OpenWindow(const char* windowName, float Width, float Height)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init error : " << SDL_GetError() << std::endl;
		exit(1);
	}

	m_MainWindow = SDL_CreateWindow(windowName, 20, 20, Width, Height, 0);
	if (m_MainWindow == NULL)
	{
		std::cout << "Erreur lors de la creation de la fenêtre" << std::endl;
		std::cout << "code de l erreur :" << SDL_GetError() << std::endl;
		exit(1);
	}

	m_Renderer = SDL_CreateRenderer(m_MainWindow, -1, 0);
	if (m_Renderer == NULL)
	{
		std::cout << "Erreur lors de la creation du renderer" << std::endl;
		std::cout << "code de l erreur :" << SDL_GetError() << std::endl;
		exit(1);
	}
	isWindowOpen = true;

}

void Window::ClearWindow()
{
	SDL_SetRenderDrawColor(m_Renderer, 0, 0, 0, 255);
	SDL_RenderClear(m_Renderer);
}


void Window::Draw(Drawable* d)
{
	d->Draw(this);
}

Window::~Window()
{
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_MainWindow);
	m_Renderer = nullptr;
	m_MainWindow = nullptr;
	isWindowOpen = false;
}
