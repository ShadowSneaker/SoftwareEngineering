#include "Label.h"

void Label::updateText() {
	surface = maxLength > 0 ? TTF_RenderText_Blended_Wrapped(font, text.c_str(), { colour.r, colour.g, colour.b }, maxLength) : TTF_RenderText_Blended(font, text.c_str(), { colour.r, colour.g, colour.b });
	texture = SDL_CreateTextureFromSurface(renderer, surface);
}

Label::Label(SDL_Renderer* renderer, int windowWidth, int windowHeight) : UIElement(renderer, windowWidth, windowHeight)
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
		updateText();
		//Render text
		/*
		SDL_Color textColor = { redValue,greenValue,blueValue };
		if (!bTexture.loadFromRenderedText(fontText.c_str(), textColor, renderer, font))
		{
			printf("Failed to render text texture!\n");
			success = false;
		}
		*/
	}

	return success;
}



void Label::RenderFont()
{
	SDL_Rect buttonSize;
	buttonSize.x = localX;
	buttonSize.y = localY;
	buttonSize.w = textWidth;
	buttonSize.h = textHeight;

	//Clip the text to the area specified
	SDL_Rect clip = { localX, localY, elementWidth, elementHeight };

	SDL_RenderSetClipRect(renderer, &clip);
	SDL_RenderCopy(renderer, this->texture, NULL, &buttonSize);
	SDL_RenderSetClipRect(renderer, NULL);
}

void Label::drawElement(SDL_Texture* texture) {
	RenderFont();
}

void Label::update()
{
}

void Label::setText(std::string text) {
	this->text = text;
}

void Label::setColour(SDL_Color colour) {
	this->colour = colour;
}

void Label::setFont(const char* fontPath, int size) {
	LoadFont(fontPath, size, text, colour.r, colour.g, colour.b);
}

void Label::setMaxLength(Uint32 length) {
	this->maxLength = length;
}

void Label::calculateDimensions() {
	int w, h;
	TTF_SizeText(font, text.c_str(), &w, &h);
	if (maxLength > 0) {
		int lines = 1;
		if (w > maxLength)
			lines = std::roundf((float)w / (float)maxLength);
		textWidth = maxLength;
		textHeight = h * lines;
	}
	else {
		textWidth = w;
		textHeight = h;
	}
}
