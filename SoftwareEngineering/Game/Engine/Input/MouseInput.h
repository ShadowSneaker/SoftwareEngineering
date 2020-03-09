#pragma once
#include <SDL.h>
//Custom libraries that aren't mine
#include "..//Graphics/Renderer/Renderer.h"
#include <CopiriteMath/Datatypes/Transform.h>

enum Mouse_enum { Mouse_Button_Left, Mouse_Button_Right, Mouse_Wheel_Down, Mouse_Wheel_Up };

class MouseInput
{
private:
	SDL_Point m_MousePos;
	bool m_Mouse_Change[sizeof(Mouse_enum)];
	float MouseWheel_y;
	float WheelStrength = 0.05;
public:
	MouseInput();
	~MouseInput() {};
	//Give it an event and it does button things
	bool UpdateMouse(SDL_Event* pass_event);
	//checks if mouse key is pressed
	bool CheckMouse(Mouse_enum button);
	//checks if mouse is on image
	bool OnImage(CImage* Image);
	//moves image
	void MoveImage(CImage* Image);
	SDL_Point getMousePos() { return m_MousePos; };
	
	float GetMouseWheel() { return MouseWheel_y; };

	void  SetMouseWheel(float image_y) { MouseWheel_y = image_y; };

	void  SetWheelStrength(float strength) { WheelStrength = strength; };

	bool ImageSelected = false;
};

