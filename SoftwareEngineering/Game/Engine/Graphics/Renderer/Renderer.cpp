#include "Renderer.h"



CRenderer::CRenderer()
{
	TheSetUp = new CSDLSetup();
	TheSetUp->Initialize();
}



CRenderer::~CRenderer()
{

}


void CRenderer::DrawAllImages()
{

}


void CRenderer::DrawImage(CImage *TheImage, std::string Name)
{
	SDL_Rect Rect;
	Rect.x = TheImage->Transform.Location.X() - TheImage->GetWorldPivot().X();
	Rect.y = TheImage->Transform.Location.Y() - TheImage->GetWorldPivot().Y();
	Rect.w = TheImage->GetCell().x * TheImage->Transform.Scale.X();
	Rect.h = TheImage->GetCell().y * TheImage->Transform.Scale.Y();




	//SDL_RenderCopyEx();
}