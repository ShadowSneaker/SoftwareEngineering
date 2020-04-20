#include "UIElement.h"

UIElement::UIElement(SDL_Renderer* renderer, int windowWidth, int windowHeight) : renderer(renderer), windowWidth(windowWidth), windowHeight(windowHeight) {
}

void UIElement::setParent(UIElement* parent) {
	this->parent = parent;
}

void UIElement::setElementSize(int width, int height) {
	elementWidth = width;
	elementHeight = height;
}

void UIElement::setAnchor(Anchor anchor) {
	anchorType = anchor;
}

void UIElement::applyAnchor() {
	float parentWidth = windowWidth, parentHeight = windowHeight;
	float parentX = 0, parentY = 0;
	if (parent != nullptr) {
		parentX = parent->localX;
		parentY = parent->localY;
		parentWidth = parent->elementWidth;
		parentHeight = parent->elementHeight;
	}
	switch (anchorType) {
	case CENTRE:
		localX = parentX + (((parentWidth / 2) - (elementWidth / 2)) + offsetX);
		localY = parentY + (((parentHeight / 2) - (elementHeight / 2)) + offsetY);
		break;
	case CENTRE_LEFT:
		localX = parentX + offsetX;
		localY = parentY + (((parentHeight / 2) - (elementHeight / 2)) + offsetY);
		break;
	case CENTRE_RIGHT:
		localX = parentX + ((parentWidth - elementWidth) + offsetX);
		localY = parentY + (((parentHeight / 2) - (elementHeight / 2)) + offsetY);
		break;
	case TOP_LEFT:
		localX = parentX + offsetX;
		localY = parentY + offsetY;
		break;
	case TOP_RIGHT:
		localX = parentX + ((parentWidth - elementWidth) + offsetX);
		localY = parentY + offsetY;
		break;
	case TOP_CENTRE:
		localX = parentX + (((parentWidth / 2) - (elementWidth / 2)) + offsetX);
		localY = parentY + offsetY;
		break;
	case BOTTOM_LEFT:
		localX = parentX + offsetX;
		localY = parentY + ((parentHeight - elementHeight) + offsetY);
		break;
	case BOTTOM_RIGHT:
		localX = parentX + ((parentWidth - elementWidth) + offsetX);
		localY = parentY + ((parentHeight - elementHeight) + offsetY);
		break;
	case BOTTOM_CENTRE:
		localX = parentX + (((parentWidth / 2) - (elementWidth / 2)) + offsetX);
		localY = parentY + ((parentHeight - elementHeight) + offsetY);
		break;
	}
}

void UIElement::drawBox(SDL_Texture* surface, float x, float y, float width, float height, SDL_Color colour) {
	SDL_Rect rect = { localX + x, localY + y, width, height };
	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderFillRect(renderer, &rect);
	//SDL_Rect rect2 = { 0, 0, 100, 100 };
	//SDL_RenderFillRect(renderer, &rect2);
}

void UIElement::setPosition(float x, float y) {
	offsetX = x;
	offsetY = y;
	applyAnchor();
}