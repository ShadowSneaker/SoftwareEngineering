#pragma once
#include <string>
#include <SDL.h>
#include "AnchorTypes.h"


//Base class for UI elements
class UIElement {

private:

	//Offset values from the anchored position
	float offsetX, offsetY;
public:
	UIElement(SDL_Renderer* renderer, int windowWidth, int windowHeight);

	void setParent(UIElement* parent);

	float windowWidth{ 800 }, windowHeight{ 600 };

	//Set the dimensions of the element
	void setElementSize(int width, int height);

	//Set the position to anchor it to
	void setAnchor(Anchor anchor);

	void applyAnchor();
	virtual void update() = 0;

	void setPosition(float x, float y);

	//Implement in child classes
	virtual void drawElement(SDL_Texture* surface) = 0;
protected:
	//Drawing functions for internal use to draw the UI element as a whole.
	//void drawString(std::string text, float x, float y, SDL_Color colour);
	//void drawTexture(std::string file, float x, float y, float width, float height);
	void drawBox(SDL_Texture* surface, float x, float y, float width, float height, SDL_Color colour);
	SDL_Renderer* renderer;
	float localX, localY, localZ;
	int elementWidth, elementHeight;
	Anchor anchorType{ Anchor::TOP_LEFT };
	UIElement* parent;
};

