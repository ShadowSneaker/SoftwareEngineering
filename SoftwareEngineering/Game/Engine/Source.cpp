#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"


int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	CRenderer* Renderer{ new CRenderer() };
	Renderer->SetBackgroundColour(SColour::DarkGray());
	
	CImage* Image{ new CImage() };
	Renderer->SetImage(Image, "Content/Images/HappyBoi.png", false);
	Renderer->AddImage(Image);

	Image->Transform.Location = 300.0f;
	Image->SetColour(0,255,0,255);

	CImage* ImageTwo{ new CImage() };
	Renderer->SetImage(ImageTwo, "Content/Images/Robo.png", false);
	Renderer->AddImage(ImageTwo);

	ImageTwo->Transform.Location = 400.0f;



	SDL_Event* Event{ new SDL_Event{} };


	while (Event->type != SDL_QUIT)
	{
		Renderer->DrawAllImages();
		SDL_PollEvent(Event);
	}

	return 1;
}