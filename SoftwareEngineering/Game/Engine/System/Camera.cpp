#include "Camera.h"
#include "../Graphics/Renderer/Renderer.h"



CCamera::CCamera()
{
	CameraOffSet = CRenderer::Instance->GetWindowSize().ToFloat() / 2.0f;
}


CCamera::CCamera(SVector2 Position)
{
	CameraOffSet = CRenderer::Instance->GetWindowSize().ToFloat() / 2.0f;
	CameraPosition = Position;
}


CCamera::~CCamera()
{}


void CCamera::CameraTesterFunction(CImage* TheImage)
{

	printf("The Cameras Off Set is ->  X: %f, Y: %f\n", CameraOffSet.GetX(), CameraOffSet.GetY());
	printf("The actual off Set should be -> X: %f, Y: %f\n", (CRenderer::Instance->GetWindowSize().ToFloat().GetX() / 2.0f), (CRenderer::Instance->GetWindowSize().ToFloat().GetY() / 2.0f));

	printf("the Images position that the camera should be centerd around -> X: %f, Y: %f\n", TheImage->Transform.Location.GetX(), TheImage->Transform.Location.GetY());
	printf("this is the position of the camera which should match the image position -> X: %f, Y: %f\n", CameraPosition.GetX(), CameraPosition.GetY());

}