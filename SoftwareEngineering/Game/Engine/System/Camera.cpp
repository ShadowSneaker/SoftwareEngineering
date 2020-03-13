#include "Camera.h"

CCamera::CCamera()
{

}

CCamera::CCamera(CSDLSetup* TheSetUp)
{
	SetUp = TheSetUp;
	Camera.w = TheSetUp->WindowSize.GetX();
	Camera.h = TheSetUp->WindowSize.GetY();

}

CCamera::CCamera(SVector2i WindowSize)
{
	Camera.w = WindowSize.GetX();
	Camera.h = WindowSize.GetY();
}


CCamera::~CCamera()
{
	if (SetUp) delete SetUp;
}


void CCamera::SetCameraPosition(float X, float Y)
{
	Camera.x = X;
	Camera.y = Y;
}


SVector2i CCamera::GetCameraPosition()
{
	SVector2i Temp;
	Temp.SetX(Camera.x);
	Temp.SetY(Camera.y);
	return Temp;
}