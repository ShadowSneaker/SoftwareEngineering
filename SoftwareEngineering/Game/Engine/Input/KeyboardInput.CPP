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


	///Check for Key Down
	if (event->type == SDL_KEYDOWN)
	{
		SDL_Keycode keyPressed = event->key.keysym.sym;
		///Check for Key Down
		if (event->type == SDL_KEYDOWN)
		{

			for (auto const& key : keybinds)
			{
				if (keyPressed == key.second)
					m_keyboardState[key.first] = true;
			}

		}

		///Check for Key Up
		else if (event->type == SDL_KEYUP)
		{

			for (auto const& key : keybinds)
			{
				if (keyPressed == key.second)
					m_keyboardState[key.first] = false;
			}

		}
	}

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
