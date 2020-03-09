#include "InputManager.h"

InputManager::InputManager()
{
	p_controller = new ControllerInput();
	p_controller->Initialization();

	p_mouse = new MouseInput();
	
	p_keyboard = new KeyboardInput();
}

InputManager::~InputManager()
{
	p_controller->Release();
	delete p_controller;
	p_controller = nullptr;

	delete p_mouse;
	p_mouse = nullptr;

	delete p_keyboard;
	p_keyboard = nullptr;
}

void InputManager::Update(SDL_Event* event)
{

	//p_controller->ReceiveEvent(event);




	p_keyboard->Update(event);



	p_mouse->UpdateMouse(event);


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
