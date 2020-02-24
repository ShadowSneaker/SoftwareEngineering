#include "AssetLoader.h"
#include <SDL_image.h>
#include <iostream>

AssetLoader::AssetLoader()
= default;

AssetLoader::~AssetLoader()
= default;

SDL_Surface* AssetLoader::LoadImage(const char* path)
{
	SDL_Surface* image = IMG_Load(path);

	if (!image)
	{
		std::cout << "IMG_Load: %s\n", IMG_GetError();
		return nullptr;
	}

	return image;
}

SDL_Texture* AssetLoader::LoadTexture(SDL_Renderer* renderer, const char* path)
{
	SDL_Surface* image = LoadImage(path);
	SDL_Texture* texture = nullptr;

	if (image != nullptr)
	{
		texture = SDL_CreateTextureFromSurface(renderer, image);
	}

	return texture;
}