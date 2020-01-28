#include "Graphics/Renderer/SDLSetup.h"



int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	CSDLSetup* Setup{ new CSDLSetup() };
	Setup->Initialize();

	SDL_Event* Event{ new SDL_Event{} };


	while (Event->type != SDL_QUIT)
	{
		SDL_PollEvent(Event);
	}

	return 1;
}