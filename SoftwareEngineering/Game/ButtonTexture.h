#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include <string>

//This class is only for testing purpose for the UI elements. It will be removed later!

class ButtonTexture
{
public:
	//Initialize Variables
	ButtonTexture();

	//Deallocate memory
	~ButtonTexture();

	//Loads image at specified path
	bool LoadFromFile(std::string path, SDL_Renderer* renderer);

	//create image from font string
	bool loadFromRenderedText(std::string textureText, SDL_Color textColor, SDL_Renderer* renderer, TTF_Font* font);

	//Deallocate texture
	void free();

	//Set colour modulation
	void SetColor(Uint8 red, Uint8 green, Uint8 blue);

	//Set blending
	void setBlendMode(SDL_BlendMode blending);

	//set alpha modulation
	void setAlpha(Uint8 alpha);

	//Renders texture at given point
	void render(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	//The actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;

};

