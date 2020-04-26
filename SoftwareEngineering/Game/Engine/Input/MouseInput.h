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
	SDL_Point m_TrueMousePos;
	SDL_Point m_OldMousePos;
	float m_posDistX;
	float m_posDistY;
	bool m_Mouse_Change[sizeof(Mouse_enum)];
	float MouseWheel_y = 0;
	float WheelStrength = 0.05;

	CImage* m_CursorImage = NULL;
	float	m_Sensitivy = 1;

	//returns where this class thinks the mouse is
	SDL_Point getMousePos() { return m_MousePos; };

public:
	MouseInput();
	~MouseInput() {};
	
	//-------------------------------OPEN FOR EXTENSION--------------------------//

	//Tells this class that what about the mouse has changed in real time
	bool UpdateMouse(SDL_Event* pass_event);
	//checks if mouse key is pressed
	bool CheckMouse(Mouse_enum button);
	
	//-------------------MODIFICATION REQUIRED---------------//

	//moves image (will move more than one image, see definition for details)
	void MoveImage(CImage* Image);

	//-------------------MODIFICATION MAY BE REQUIRED---------------//

	//Sets the cursor to a given image
	void  SetCursorImage(CImage* image) { m_CursorImage = image; };

	//checks if mouse is on image
	bool OnImage(CImage* Image);

	//--------------------------CLOSED---------------------------------//

	//gets the position of the mouse wheel
	float GetMouseWheel() { return MouseWheel_y; };
	//sets the position of the mouse wheel
	void  SetMouseWheel(float image_y) { MouseWheel_y = image_y; };
	//Wheel Sensitivity
	void  SetWheelStrength(float strength) { WheelStrength = strength;};
	//Sets the speed this class thinks the mouse is moving at
	void  SetSensitivity(float Sensitivity) { m_Sensitivy = Sensitivity; };


	bool ImageSelected = false;
};

