#include "Camera.h"

CCamera::CCamera()
{
	CameraOffSet.SetX(400);
	CameraOffSet.SetY(300);
}

CCamera::CCamera(SVector2 Position)
{
	CameraOffSet.SetX(400);
	CameraOffSet.SetY(300);

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