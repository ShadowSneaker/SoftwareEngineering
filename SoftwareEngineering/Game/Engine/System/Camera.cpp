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