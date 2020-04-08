#include "FontLoader.h"

int FontLoader::mWidth = 0;
int FontLoader::mHeight = 0;

FontLoader::FontLoader()
{}

FontLoader::~FontLoader()
{}

// Load texture from existing file
SDL_Texture* FontLoader::LoadFromFile(const char* path, SDL_Renderer * renderer)
{
	// Load texture with assetloader
	SDL_Surface* image = AssetLoader::LoadImage(path);
	if (image == NULL) return nullptr;

	// Set color key
	SDL_SetColorKey(image, SDL_TRUE, SDL_MapRGB(image->format, 0, 0xFF, 0xFF));

	// Create texture from surface pixels
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	if (texture == NULL) 
	{
		printf("Unable to create texture from %s! SDL ERROR: &s\n", path, SDL_GetError());
		return nullptr;
	}

	// Save image dimensions
	mWidth = image->w;
	mHeight = image->h;

	// Delete old surface
	SDL_FreeSurface(image);

	return texture;
}

// Load from ttf file
SDL_Texture* FontLoader::LoadFromRenderedText(const char* texturePath, SDL_Color textColor, SDL_Renderer* renderer, TTF_Font* font)
{
	// Load image from ttf
	SDL_Surface* image = TTF_RenderText_Blended(font, texturePath, textColor);
	if (image == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
		return nullptr;
	}

	// Create texture from surface pixels
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image);
	if (texture == NULL)
	{
		printf("Unable to create texture from rendered text! SDL_Error: %s\n", SDL_GetError());
		return nullptr;
	}

	// Save image dimensions
	mWidth = image->w;
	mHeight = image->h;

	// Delete old surface
	SDL_FreeSurface(image);

	return texture;
}