#pragma once
//Using SDL and other libaries
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include <cmath>
#include "ButtonTexture.h"

class ImageBox
{
private:
	SDL_Renderer* renderer;
	ButtonTexture picture;

public:
	//Initialize variables
	ImageBox(SDL_Renderer* temprenderer);

	//Deallocate Memory
	~ImageBox();

	//Load the picture to show
	void LoadPicture(const char* imageLoactionString);

	//Render the picture to the screen
	void RenderPicture(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha, double degreesOfRotation, SDL_RendererFlip flipType);

};

