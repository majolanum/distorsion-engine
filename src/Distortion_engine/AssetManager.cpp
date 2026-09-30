#include "AssetManager.h"
#include <SDL3_image/SDL_image.h>

void AssetManager::LoadImage(std::string imagePath)
{
	SDL_Surface* surface = IMG_Load(imagePath.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(m_Window->m_Renderer, surface);
	m_AllLoadedImage.emplace(imagePath, std::move(texture));
}

SDL_Texture* AssetManager::GetImage(std::string ImagePath)
{
	if (m_AllLoadedImage.contains(ImagePath))
	{
		auto Image = m_AllLoadedImage.find(ImagePath);
		if (Image != m_AllLoadedImage.end())
			return Image->second;
	}
	else
		LoadImage(ImagePath);
}
