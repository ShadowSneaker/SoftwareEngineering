#include "Label.h"

Label::Label(SDL_Renderer* temprenderer, TTF_Font* tempFont) : renderer(temprenderer), font(tempFont)
{
	
}

Label::~Label()
{
	//Free loaded images
	bTexture.free();

	//Free loaded fonts
	TTF_CloseFont(font);
	font = NULL;

}

bool Label::LoadFont(const char* fontLocationString, int fontSize, std::string fontText, Uint8 redValue, Uint8 greenValue, Uint8 blueValue)
{
	//Loading success flag
	bool success = true;

	//Open the font
	font = TTF_OpenFont(fontLocationString, fontSize);
	if (font == NULL)
	{
		printf("Failed to load specified font! SDL_ttf error: %s \n", TTF_GetError());
		success = false;
	}
	else
	{
		//Render text
		SDL_Color textColor = { redValue,greenValue,blueValue };
		if (!bTexture.loadFromRenderedText(fontText.c_str(), textColor, renderer, font))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
	}

	return success;
}

void Label::RenderFont(int x, int y, Uint8 red, Uint8 green, Uint8 blue, Uint8 alpha, double degreesOfRotation, SDL_RendererFlip flipType)
{
	//Clear screen
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);

	//Render current frame

	SDL_Rect buttonSize;
	buttonSize.x = 0;
	buttonSize.y = 0;
	buttonSize.w = bTexture.getWidth();
	buttonSize.h = bTexture.getHeight();


	//Render background color

	SDL_Rect backgroundRect = { x, y, bTexture.getWidth(), bTexture.getHeight() };
	SDL_SetRenderDrawColor(renderer, red, green, blue, alpha);
	SDL_RenderFillRect(renderer, &backgroundRect);


	//Render text
	bTexture.setAlpha(alpha);
	bTexture.render(renderer, x, y, &buttonSize, degreesOfRotation, NULL, flipType);

	//Update screen
	SDL_RenderPresent(renderer);
}
