#pragma once
#include "..//Graphics/Renderer/SDLSetup.h"


class CCamera
{
private: 
	///properties
	
	// The Cameras Position
	SVector2 CameraPosition = { 0,0 };

	// The Cameras OffSet
	SVector2 CameraOffSet = {0, 0};

	// The SDL Setup
	CSDLSetup* SetUp = nullptr;

public: 
	///Constructors

	// constructor, default
	CCamera();

	//
	CCamera(SVector2 Position);

	//destructor
	~CCamera();

public:
	///functions 

	// this function takes the variable and sets the cameras x position to this variable
	// @Param X - the X position for the Camera
	INLINE void SetCameraX(float X) { CameraPosition.SetX(X); }

	// this function takes the variable and sets the cameras y position to this vairbale
	// @Param Y - The Y position for the Camera
	INLINE void SetCameraY(float Y) { CameraPosition.SetY(Y); }

	// this function takes the vairable and sets the cameras x and y position to the variables put it
	// @Param X - The X position for the Camera
	// @Param Y - The Y position for the Camera
	void SetCameraPosition(float X, float Y);


	// this function returns the cameras X posiion
	INLINE float GetCameraX() { return CameraPosition.GetX(); }

	// this function returns the cameras Y position
	INLINE float GetCameraY() { return CameraPosition.GetY(); };

	// this function returns the Cameras Offset X position
	INLINE float GetCameraOffSetX() { return CameraOffSet.GetX(); };

	// this function returns the Cameras Offset Y position
	INLINE float GetCameraOffSetY() { return CameraOffSet.GetY(); };

	//this function Returns the Camera position vector
	SVector2 GetCameraPosition();


};