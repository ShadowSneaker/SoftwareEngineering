#pragma once

#include <map>
#include <SDL.h>

//each of the keys in the following list needs to have an if case in the update method for a key up event as well as a key down event
//it should look like this
//
//if (keyPressed == keybinds[KEYNAME])
//m_keyboardState[KEYNAME] = true/false;
//
//true for keydown and false for keyup
enum KEY_LIST
{
	KEY_CANCEL,
	KEY_CONFIRM,
	KEY_LEFT,
	KEY_RIGHT,
	KEY_UP,
	KEY_DOWN
};

class KeyboardInput
{
private:
	static const int m_keylist_size = 6;

	//keyboard states compare the current state with the state of the last update
	bool m_keyboardState[m_keylist_size];
	bool m_oldKeyboardState[m_keylist_size];

	//the keybinds map defines which sdl keycode a keyname is linked to
	std::map<KEY_LIST, SDL_Keycode> keybinds =
	{
		{KEY_CANCEL,SDLK_ESCAPE},
		{KEY_CONFIRM,SDLK_SPACE},
		{KEY_LEFT,SDLK_a},
		{KEY_RIGHT,SDLK_d},
		{KEY_UP,SDLK_w},
		{KEY_DOWN,SDLK_s}
	};
public:
	KeyboardInput();
	~KeyboardInput();
	void Update( SDL_Event* event );
	bool IsKeyPressed(KEY_LIST key);
	bool KeyDown(KEY_LIST key);
	bool KeyUp(KEY_LIST key);
};

