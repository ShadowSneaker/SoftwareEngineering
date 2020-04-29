#pragma once
#include "UIElement.h"
#include "UIBuilderFactory.h"
#include "../Graphics/Renderer/SDLSetup.h"
#include "../Graphics/Renderer/Renderer.h"
#include <vector>

class UIBase {
private:
	SDL_Texture* surface;
	SDL_Renderer* renderer;
	std::vector<UIElement*> elements;
public:
	UIBase(CRenderer* renderer);
	virtual void drawAllElements();
	void addElement(UIElement* element);
	void removeElement(UIElement* element);
	void updateAllElements();
	virtual void update() = 0;
protected:
	BuilderFactory* factory;
};