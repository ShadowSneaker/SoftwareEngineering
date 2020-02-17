#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"
#include "Input/MouseInput.h"
#include "Input/KeyboardInput.h"


int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	CRenderer* Renderer{ new CRenderer() };

	MouseInput* mouse = new MouseInput();
	KeyboardInput* Keyboard = new KeyboardInput();

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
		if(mouse->UpdateMouse(Event));
		{
			if ((mouse->CheckButton(Left) && (mouse->OnImage(Image))) || mouse->ImageSelected)
			{
				Image->SetColour(255, 0, 0, 255);
				mouse->MoveImage(Image);
			}
			else if (mouse->CheckButton(Left))
				Image->SetColour(0, 255, 0, 255);

			if (mouse->CheckButton(Right) && mouse->OnImage(Image))
				Renderer->SetBackgroundColour(SColour::Blue());
			else if (mouse->CheckButton(Right))
				Renderer->SetBackgroundColour(SColour::Black());
		}
	}
	delete mouse;
	mouse = nullptr;

	delete Keyboard;
	Keyboard = nullptr;

	return 1;
}