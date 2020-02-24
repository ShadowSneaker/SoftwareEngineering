#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"
#include "Graphics/Images/Animation.h"



int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	CRenderer* Renderer{ new CRenderer() };
	Renderer->SetBackgroundColour(SColour::DarkGray());
	
	CAnimation* Image{ new CAnimation() };
	Image->SetImage("Content/Images/Anim.png");
	Renderer->AddImage(Image);

	Image->SetCellCount(1, 6);
	Image->Transform.Location = 300.0f;
	Image->Speed = 0.1f;
	Image->Transform.Scale = 1.0f;

	SDL_Event* Event{ new SDL_Event{} };


	while (Event->type != SDL_QUIT)
	{
		Renderer->DrawAllImages();
		SDL_PollEvent(Event);
	}

	return 1;
}