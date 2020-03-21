#pragma once
//Using SDL and other libaries
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "ButtonTexture.h"
#include "Engine/UI/UIElement.h"

class Label
{
private:

	SDL_Renderer* renderer;
	TTF_Font* font;
	//The include for the text loading and rendering is still missing so a test file is added
	ButtonTexture bTexture;

public:
	//Initialize variables
	Label(SDL_Renderer* temprenderer, TTF_Font* tempFont);

	//Deallocate Memory
	~Label();

	//Load the font
	bool LoadFont(const char* fontLocationString, int fontSize, std::string fontText, Uint8 redValue, Uint8 greenValue, Uint8 blueValue);

	//Render the font
	void RenderFont(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha, double degreesOfRotation, SDL_RendererFlip flipType);


};

