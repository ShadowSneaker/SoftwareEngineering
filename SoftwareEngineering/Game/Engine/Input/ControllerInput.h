#include "SDL_gamecontroller.h"
#include "SDL.h"
#pragma once
class ControllerInput
{
private:
	SDL_Joystick* Controller = NULL;
	const int JOYSTICK_DEAD_ZONE = 8000;
	int xDirection = 0;
	int yDirection = 0;
public:
	bool Initialization();
	void ReceiveEvent(SDL_Event* event);
	void Release();
	~ControllerInput();
	ControllerInput();



};

