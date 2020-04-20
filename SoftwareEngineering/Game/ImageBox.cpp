#include "ImageBox.h"

ImageBox::ImageBox(SDL_Renderer* temprenderer) : renderer(temprenderer)
{

}

ImageBox::~ImageBox()
{
	//Free loaded images
	picture.free();

}

void ImageBox::LoadPicture(const char* imageLoactionString)
{
	//Load image
	if (!picture.LoadFromFile(imageLoactionString, renderer)) {
		printf("Failed to load texture!\n");
	}
	else {
		//Set standard alpha blending
		picture.setBlendMode(SDL_BLENDMODE_BLEND);
	}

}

void ImageBox::RenderPicture(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha, double degreesOfRotation, SDL_RendererFlip flipType)
{
	//Clear screen
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	//Render current frame

	SDL_Rect pictureSize;
	pictureSize.x = 0;
	pictureSize.y = 0;
	pictureSize.w = picture.getWidth();
	pictureSize.h = picture.getHeight();

	//Render image
	picture.setAlpha(alpha);
	picture.render(renderer, x, y, &pictureSize, degreesOfRotation, NULL, flipType);

	//Update screen
	SDL_RenderPresent(renderer);
}
