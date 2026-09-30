#pragma once
#include <map>
#include <string>

#include "Window.h"

struct SDL_Texture;

class AssetManager
{
private:
	Window* m_Window;
	std::map<std::string, SDL_Texture*> m_AllLoadedImage;

	void LoadImage(std::string imagePath);
	void GetWindow(Window* w) { m_Window = w; }

public:
	SDL_Texture* GetImage(std::string ImagePath);

	friend class Application;
};

