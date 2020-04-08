#pragma once
#include "AssetLoader.h"
#include <SDL_ttf.h>
#include <stdio.h>

class FontLoader
{
public:
	static int mWidth;
	static int mHeight;

	FontLoader();
	~FontLoader();

	// Loads image at specified path
	static SDL_Texture* LoadFromFile(const char* path, SDL_Renderer* renderer);

	// Create image from font string
	static SDL_Texture* LoadFromRenderedText(const char* texture, SDL_Color textColor, SDL_Renderer* renderer, TTF_Font* font);
};

