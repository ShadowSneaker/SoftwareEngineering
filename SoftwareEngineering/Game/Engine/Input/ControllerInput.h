#include "SDL_gamecontroller.h"
#include "SDL.h"
#include "..//Graphics/Renderer/Renderer.h"
#include "..//Graphics/Images/Animation.h"
#include <CopiriteMath/Datatypes/Transform.h>
#pragma once
// MADE BY KERON SEPP
class ControllerInput
{
private:
	SDL_Joystick* Controller = NULL;
	const int JOYSTICK_DEAD_ZONE = 8000;
	float jAxisNormalised = 0;
public:
	int xDirection = 0;
	int yDirection = 0;
	double JoyStickAngle = 0;

	bool Initialization();
	void ReceiveEvent(SDL_Event* event);
	void MoveImage(CAnimation* Image);
	void Release();
	double CalculateJSAngle(int xDirecton, int yDirection);
	~ControllerInput();
	ControllerInput();
	   
};

