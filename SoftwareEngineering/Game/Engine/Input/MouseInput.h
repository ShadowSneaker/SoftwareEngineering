#pragma once
#include <SDL.h>
//Custom libraries that aren't mine
#include "..//Graphics/Renderer/Renderer.h"
#include <CopiriteMath/Datatypes/Transform.h>

enum Clicks { Left, Right };

class MouseInput
{
private:
	SDL_Point m_MousePos;
	bool m_Mouse_Buttons_Pressed[sizeof(Clicks)];
public:
	MouseInput();
	~MouseInput() {};
	//Give it an event and it does button things
	bool UpdateMouse(SDL_Event* pass_event);
	//checks if mouse key is pressed
	bool CheckButton(Clicks button);
	//checks if mouse is on image
	bool OnImage(CImage* Image);
	//moves image
	void MoveImage(CImage* Image);
	SDL_Point getMousePos();

	bool ImageSelected = false;
};

