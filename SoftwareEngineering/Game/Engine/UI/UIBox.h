#pragma once
#include "UIElement.h"
#include "../Graphics/Images/Image.h"

class UIBox : public UIElement {
private:
	SDL_Color colour;
	CImage image;
public:
	UIBox(SDL_Renderer* renderer, int windowWidth, int windowHeight);

	void drawElement(SDL_Texture* surface) override;
	void update() override;

	void setColour(SDL_Color colour);
	void setImage(CImage image);
};