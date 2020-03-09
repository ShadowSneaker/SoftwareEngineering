#include "KeyboardInput.h"

KeyboardInput::KeyboardInput()
{

	for (int i = 0; i < m_keylist_size; i++)
	{
		m_oldKeyboardState[i] = false;
	}

	for (int i = 0; i < m_keylist_size; i++)
	{
		m_keyboardState[i] = false;
	}

}

KeyboardInput::~KeyboardInput()
{
}

void KeyboardInput::Update(SDL_Event* event)
{

	//transfer the new keyboard state to the old one
	for (int i = 0; i < m_keylist_size; i++)
	{
		m_oldKeyboardState[i] = m_keyboardState[i];
	}

	if (SDL_PollEvent(event) != NULL)
	{
		///Check for Key Down
		if (event->type == SDL_KEYDOWN)
		{
			SDL_Keycode keyPressed = event->key.keysym.sym;

			if (keyPressed == keybinds[KEY_CANCEL])
				m_keyboardState[KEY_CANCEL] = true;

			else if (keyPressed == keybinds[KEY_CONFIRM])
				m_keyboardState[KEY_CONFIRM] = true;

			else if (keyPressed == keybinds[KEY_DOWN])
				m_keyboardState[KEY_DOWN] = true;

			else if (keyPressed == keybinds[KEY_LEFT])
				m_keyboardState[KEY_LEFT] = true;

			else if (keyPressed == keybinds[KEY_RIGHT])
				m_keyboardState[KEY_RIGHT] = true;

			else if (keyPressed == keybinds[KEY_UP])
				m_keyboardState[KEY_UP] = true;
		}

		///Check for Key Up
		else if (event->type == SDL_KEYUP)
		{
			SDL_Keycode keyPressed = event->key.keysym.sym;

			if (keyPressed == keybinds[KEY_CANCEL])
				m_keyboardState[KEY_CANCEL] = false;

			else if (keyPressed == keybinds[KEY_CONFIRM])
				m_keyboardState[KEY_CONFIRM] = false;

			else if (keyPressed == keybinds[KEY_DOWN])
				m_keyboardState[KEY_DOWN] = false;

			else if (keyPressed == keybinds[KEY_LEFT])
				m_keyboardState[KEY_LEFT] = false;

			else if (keyPressed == keybinds[KEY_RIGHT])
				m_keyboardState[KEY_RIGHT] = false;

			else if (keyPressed == keybinds[KEY_UP])
				m_keyboardState[KEY_UP] = false;
		}

	};
}

bool KeyboardInput::IsKeyPressed(KEY_LIST key)
{
	return m_keyboardState[key];
}

bool KeyboardInput::KeyDown(KEY_LIST key)
{
	if (m_oldKeyboardState[key] == false && m_keyboardState[key] == true)
		return true;

	else return false;
}

bool KeyboardInput::KeyUp(KEY_LIST key)
{
	if (m_oldKeyboardState[key] == true && m_keyboardState[key] == false)
		return true;

	else return false;
}
