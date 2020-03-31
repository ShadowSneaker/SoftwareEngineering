#pragma once
#include "..//Graphics/Renderer/SDLSetup.h"
#include "../Graphics/Images/Image.h"


//
class CCamera
{
private: 
	///properties
	
	// The Cameras Position.
	SVector2 CameraPosition { 0.0f };

	// The Cameras OffSet.
	SVector2 CameraOffSet { 0.0f };



public: 
	///Constructors

	// Constructor, Default.
	CCamera();

	// Constructor, Initiates the camera with a default position.
	// @param Position - The location this camera should be created at.
	CCamera(SVector2 Position);

	// Destructor.
	~CCamera();



public:

	///function

	// A function to test the cameras off set is bieng calculated correctly and is bieng applied 
	// @param the image that the camera has been centred on to test the cameras position against it
	void CameraTesterFunction(CImage* TheImage);



	/// Setters

	// Sets the X location of this camera.
	// @param X - The value to set X.
	INLINE void SetCameraX(float X) { CameraPosition.SetX(X); }

	// Sets the Y location of this camera.
	// @param Y - The value to set Y.
	INLINE void SetCameraY(float Y) { CameraPosition.SetY(Y); }

	// Sets the location of this camera.
	// @param X - The value to set X.
	// @param Y - The value to set Y.
	INLINE void SetCameraPosition(float X, float Y) { CameraPosition = { X, Y }; }



	/// Getters

	// Returns the X location of this camera.
	INLINE float GetCameraX() const { return CameraPosition.GetX(); }

	// Returns the Y location of this camera.
	INLINE float GetCameraY() const { return CameraPosition.GetY(); };

	// Returns the X offet of this camera.
	INLINE float GetCameraOffSetX() const { return CameraOffSet.GetX(); };

	// Returns the Y offset of this camera.
	INLINE float GetCameraOffSetY() const { return CameraOffSet.GetY(); };

	// Returns the location of this camera.
	INLINE SVector2 GetCameraPosition() const { return CameraPosition; }


	
};