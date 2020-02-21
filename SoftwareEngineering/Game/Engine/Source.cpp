#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"
#include "Graphics/Images/Animation.h"


int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	CRenderer* Renderer{ new CRenderer() };
	Renderer->SetBackgroundColour(SColour::DarkGray());
	
	CAnimation* Image{ new CAnimation() };
	Image->SetImage("Content/Images/HappyBoi.png");
	Renderer->AddImage(Image);

	Image->SetCellCount(1, 5);
	Image->Transform.Location = 300.0f;
	Image->SetColour(0,255,0,255);

	SDL_Event* Event{ new SDL_Event{} };


	while (Event->type != SDL_QUIT)
	{
		Renderer->DrawAllImages();
		SDL_PollEvent(Event);
	}

	return 1;
}