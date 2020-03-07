#pragma once
#include "MouseInput.h"
#include "KeyboardInput.h"
#include "ControllerInput.h"
class InputManager
{
private:
	ControllerInput* p_controller;
	MouseInput* p_mouse;
	KeyboardInput* p_keyboard;
public:
	InputManager();
	~InputManager();
	void Update(SDL_Event* event);
	ControllerInput* GetController();
	MouseInput* GetMouse();
	KeyboardInput* GetKeyboard();
};

