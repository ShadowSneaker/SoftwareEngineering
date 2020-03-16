#include "Camera.h"

CCamera::CCamera()
{

}

CCamera::CCamera(SVector2 Position)
{
	CameraPosition = Position;
}

CCamera::~CCamera()
{
}


void CCamera::SetCameraPosition(float X, float Y)
{
	CameraPosition.SetX(X);
	CameraPosition.SetY(Y);
}


SVector2 CCamera::GetCameraPosition()
{
	return CameraPosition;
}