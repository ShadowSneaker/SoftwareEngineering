#include "Button.h"

using namespace std;

const int BUTTON_WIDTH = 300;
const int BUTTON_HEIGHT = 200;

enum ButtonSprite {
	BUTTON_SPRITE_MOUSE_OUT = 0,
	BUTTON_SPRITE_MOUSE_OVER = 1,
	BUTTON_SPRITE_MOUSE_DOWN = 2,
	BUTTON_SPRITE_MOUSE_UP = 3,
	BUTTON_SPRITE_TOTAL = 4
};

class Button {
public:
	Button();
	void setPosition(int x, int y);
	void handleEvent(SDL_Event* e);
	void render();

private:
	SDL_Point mPosition;
	ButtonSprite mCurrentSprite;
};

Button::Button() {
	mPosition.x = 0;
	mPosition.y = 0;

	mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
}

void Button::setPosition(int x, int y) {
	mPosition.x = x;
	mPosition.y = y;
}

void Button::handleEvent(SDL_Event* e) {
	if (e->type == SDL_MOUSEMOTION || e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP) {
		int x, y;
		SDL_GetMouseState(&x, &y);

		bool inside = true;

		//check where mouse is
		//left side of button
		if (x < mPosition.x) {
			inside = false;
		}
		//rigth side of button
		else if (x > mPosition.x + BUTTON_WIDTH) {
			inside = false;
		}
		//above button
		else if (y < mPosition.y) {
			inside = false;
		}
		//below button
		else if (y > mPosition.y + BUTTON_HEIGHT) {
			inside = false;
		}


		if (!inside) {
			mCurrentSprite = BUTTON_SPRITE_MOUSE_OUT;
		}
		else {
			switch (e->type) {
			case SDL_MOUSEMOTION:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_OVER;
				break;

			case SDL_MOUSEBUTTONDOWN:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_DOWN;
				break;

			case SDL_MOUSEBUTTONUP:
				mCurrentSprite = BUTTON_SPRITE_MOUSE_UP;
				break;

			}

		}

	}
}

void Button::render() {

}