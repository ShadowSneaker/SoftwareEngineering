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

#define FONT_ROBOTO "Content/Fonts/Roboto-Regular.ttf"

class Label : public UIElement
{
private:
	TTF_Font* font;
	SDL_Surface* surface;
	SDL_Texture* texture;
	//The include for the text loading and rendering is still missing so a test file is added
	ButtonTexture bTexture;
	std::string text;
	int textWidth, textHeight;
	SDL_Color colour;
	int size;
	//wrapping length
	Uint32 maxLength;
	void updateText();
public:
	//Initialize variables
	Label(SDL_Renderer* temprenderer, int windowWidth, int windowHeight);

	//Deallocate Memory
	~Label();

	//Load the font
	bool LoadFont(const char* fontLocationString, int fontSize, std::string fontText, Uint8 redValue, Uint8 greenValue, Uint8 blueValue);

	//Render the font
	void RenderFont();

	void drawElement(SDL_Texture* texture) override;
	void update() override;

	void setText(std::string text);
	void setColour(SDL_Color colour);
	void setFont(const char* fontPath, int size);
	void setMaxLength(Uint32 length);

	void calculateDimensions();
};

