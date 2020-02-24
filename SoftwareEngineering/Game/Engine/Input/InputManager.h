#pragma once
#include "MouseInput.h"
#include "KeyboardInput.h"
#include "InputController.h"
class InputManager
{
private:
	InputController* p_controller;
	MouseInput* p_mouse;
	KeyboardInput* p_keyboard;
public:
	InputManager();
	~InputManager();
	void Update(SDL_Event* event);
	InputController* GetController();
	MouseInput* GetMouse();
	KeyboardInput* GetKeyboard();
};

