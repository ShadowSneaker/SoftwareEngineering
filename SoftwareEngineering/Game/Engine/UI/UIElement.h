#include <string>
#include <SDL.h>
#pragma once
//Anchor is used for relative positioning
enum Anchor {
	TOP_LEFT, TOP_CENTRE, TOP_RIGHT,
	CENTRE_LEFT, CENTRE, CENTRE_RIGHT,
	BOTTOM_LEFT, BOTTOM_CENTRE, BOTTOM_RIGHT
};

//Base class for UI elements
class UIElement {

private:
	float localX, localY, localZ;
	float elementWidth, elementHeight;

	SDL_Renderer* renderer;
	SDL_Texture* surface;
public:
	UIElement(SDL_Renderer* renderer, int windowWidth, int windowHeight);

	//Offset values from the anchored position
	float offsetX, offsetY;
	float windowWidth{ 800 }, windowHeight{ 600 };

	//Set the dimensions of the element
	void setElementSize(float width, float height);

	//Set the position to anchor it to
	void setAnchor(Anchor anchor);

	Anchor anchorType;
	void applyAnchor();
	void update();

	//Implement in child classes
	virtual void drawElement() = 0;
protected:
	//Drawing functions for internal use to draw the UI element as a whole.
	void drawString(std::string text, float x, float y, SDL_Color colour);
	void drawTexture(std::string file, float x, float y, float width, float height);
	void drawBox(float x, float y, float width, float height, SDL_Color colour);

};

