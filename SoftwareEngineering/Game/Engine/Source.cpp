#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"


int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	CRenderer* Renderer{ new CRenderer() };


	SDL_Event* Event{ new SDL_Event{} };


	while (Event->type != SDL_QUIT)
	{
		Renderer->DrawAllImages();
		SDL_PollEvent(Event);
	}

	return 1;
}