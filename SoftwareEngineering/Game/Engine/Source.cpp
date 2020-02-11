#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"
#include "..//MouseInput.h"

int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	CRenderer* Renderer{ new CRenderer() };

	MouseInput* mouse = new MouseInput();

	Renderer->SetBackgroundColour(SColour::DarkGray());
	
	CImage* Image{ new CImage() };
	Renderer->SetImage(Image, "Content/Images/HappyBoi.png", false);
	Renderer->AddImage(Image);

	Image->Transform.Location = 300.0f;
	Image->SetColour(0,255,0,255);

	SDL_Event* Event{ new SDL_Event{} };


	while (Event->type != SDL_QUIT)
	{
		Renderer->DrawAllImages();
		SDL_PollEvent(Event);
		//mouse stuff
		mouse->UpdateMouse(Event);
		if (mouse->CheckButton(Left))
		{
			if (mouse->OnImage(Image))
				Image->SetColour(255, 0, 0, 255);
			else
				Image->SetColour(0, 255, 0, 255);
			mouse->MoveImage(Image);
		}
		if (mouse->CheckButton(Right))
			Renderer->SetBackgroundColour(SColour::Blue());
	}

	return 1;
}