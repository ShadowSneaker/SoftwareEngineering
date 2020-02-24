#pragma once
#include <SDL.h>

class AssetLoader
{
public:
	AssetLoader();
	~AssetLoader();

	static SDL_Surface* LoadImage(const char* path);

	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* path);
};