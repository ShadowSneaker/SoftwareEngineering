#pragma once
#include "..//Graphics/Renderer/SDLSetup.h"


class CCamera
{
private: 
	///properties

	// The cameras rect
	SDL_Rect Camera = {0,0,0,0};
	
	// The SDL Setup
	CSDLSetup* SetUp = NULL;

public: 
	///Constructors

	CCamera();

	CCamera(CSDLSetup* TheSetUp);

	CCamera(SVector2i WindowSize);

	~CCamera();

public:
	///functions 

	// this function takes the variable and sets the cameras x position to this variable
	// @Param X - the X position for the Camera
	void SetCameraX(float X) { Camera.x = X; }

	// this function takes the variable and sets the cameras y position to this vairbale
	// @Param Y - The Y position for the Camera
	void SetCameraY(float Y) { Camera.y = Y; }

	// this function takes the vairable and sets the cameras x and y position to the variables put it
	// @Param X - The X position for the Camera
	// @Param Y - The Y position for the Camera
	void SetCameraPosition(float X, float Y);


	// this function returns the cameras X posiion
	float GetCameraX() { return Camera.x; }

	// this function returns the cameras Y position
	float GetCameraY() { return Camera.y; };

	//this function Returns the Camera position vector
	SVector2i GetCameraPosition();


};