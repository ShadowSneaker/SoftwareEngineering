#include "UIElement.h"

UIElement::UIElement(SDL_Renderer* renderer, int windowWidth, int windowHeight) : renderer(renderer), windowWidth(windowWidth), windowHeight(windowHeight) {
	anchorType = CENTRE;
	elementHeight = 10;
	elementWidth = 10;
	surface = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, windowWidth, windowHeight);
}

void UIElement::setElementSize(float width, float height) {
	elementWidth = width;
	elementHeight = height;
}

void UIElement::setAnchor(Anchor anchor) {
	anchorType = anchor;
}

void UIElement::applyAnchor() {
	switch (anchorType) {
	case CENTRE:
		localX = ((windowWidth / 2) - (elementWidth / 2)) + offsetX;
		localY = ((windowHeight / 2) - (elementHeight / 2)) + offsetY;
		break;
	case TOP_LEFT:
		localX = offsetX;
		localY = offsetY;
		break;
	case TOP_RIGHT:
		localX = (windowWidth - elementWidth) + offsetX;
		localY = offsetY;
		break;
	case TOP_CENTRE:
		localX = ((windowWidth / 2) - (elementWidth / 2)) + offsetX;
		localY = offsetY;
		break;
	//TODO: the rest of the anchors
	}
}

void UIElement::drawBox(float x, float y, float width, float height, SDL_Color colour) {
	SDL_Rect rect = { localX + x, localY + y, width, height };
	SDL_SetRenderTarget(renderer, surface);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	//SDL_RenderClear(renderer);
	SDL_RenderDrawRect(renderer, &rect);
	SDL_SetRenderDrawColor(renderer, colour.r, colour.g, colour.b, colour.a);
	SDL_RenderFillRect(renderer, &rect);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, surface, NULL, NULL);
	SDL_RenderPresent(renderer);
}

void UIElement::update() {
	applyAnchor();
}
