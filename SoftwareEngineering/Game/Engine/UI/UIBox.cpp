#include "UIBox.h"

UIBox::UIBox(SDL_Renderer* renderer, int windowWidth, int windowHeight) : UIElement(renderer, windowWidth, windowHeight) {

}

void UIBox::drawElement(SDL_Texture* surface) {
	drawBox(surface, 0, 0, this->elementWidth, this->elementHeight, this->colour);
}

void UIBox::update(){
}

void UIBox::setColour(SDL_Color colour) {
	this->colour = colour;
}

void UIBox::setImage(CImage image) {
	this->image = image;
}
