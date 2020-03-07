#include "InputManager.h"

InputManager::InputManager()
{
	p_controller = new ControllerInput();
	p_controller->Initialization();


}

InputManager::~InputManager()
{
	p_controller->Release();
	delete p_controller;
	delete p_mouse;
	delete p_keyboard;
}

void InputManager::Update(SDL_Event* event)
{
	if (event->type == SDL_CONTROLLERDEVICEADDED || event->type == SDL_CONTROLLERDEVICEREMOVED)
	{
		p_controller->ReceiveEvent(event);
	}


	if (event->type == SDL_KEYDOWN || event->type == SDL_KEYUP)
	{
		p_keyboard->Update(event);
	}


	p_mouse->UpdateMouse(event);

	//p_controller->Update();
}

ControllerInput* InputManager::GetController()
{
	return p_controller;
}

MouseInput* InputManager::GetMouse()
{
	return p_mouse;
}

KeyboardInput* InputManager::GetKeyboard()
{
	return p_keyboard;
}
