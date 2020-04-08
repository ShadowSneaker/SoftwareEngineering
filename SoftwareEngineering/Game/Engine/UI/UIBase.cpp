#include "UIBase.h"

#include <iostream>

UIBase::UIBase(CRenderer* renderer) {
	this->renderer = renderer->GetSDLRenderer();
	surface = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, renderer->GetWindowSize().GetX(), renderer->GetWindowSize().GetY());
	factory = new BuilderFactory( renderer );
}

void UIBase::drawAllElements() {
	Uint8 r, g, b, a;
	SDL_SetRenderTarget(renderer, surface);
	SDL_GetRenderDrawColor(renderer, &r, &g, &b, &a);
	SDL_RenderClear(renderer);

	for (int i = 0; i < elements.size(); i++) {
		elements[i]->drawElement(surface);
	}
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_SetRenderTarget(renderer, NULL);
	SDL_RenderCopy(renderer, surface, NULL, NULL);
}

void UIBase::addElement(UIElement* element) {
	elements.push_back(element);
}

void UIBase::updateAllElements() {
	for (int i = 0; i < elements.size(); i++) {
		elements[i]->update();
	}
}