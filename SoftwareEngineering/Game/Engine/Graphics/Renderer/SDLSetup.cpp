#include "SDLSetup.h"



CSDLSetup::CSDLSetup()
{}


CSDLSetup::~CSDLSetup()
{
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	SDL_Quit();
}


bool CSDLSetup::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("Error: Failed to initiate SDL!");
		return false;
	}

	if (TTF_Init() != 0)
	{
		printf("Error: Failed to initate TTF!");
		return false;
	}

	SDL_GetCurrentDisplayMode(0, &DisplayMode);
	return CreateDisplay();
}


bool CSDLSetup::CreateDisplay()
{
	if (Renderer) SDL_DestroyRenderer(Renderer);
	if (Window) SDL_DestroyWindow(Window);

	Window = SDL_CreateWindow(WindowName.c_str(), (DisplayMode.w / 2) - (WindowSize[X] / 2), (DisplayMode.h / 2) - (WindowSize[Y] / 2), WindowSize[X], WindowSize[Y], GetWindowFlags());
	if (!Window)
	{
		printf("Failed to create window!");
		SDL_Quit();
		return false;
	}

	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!Renderer)
	{
		printf("Failed to create renderer!");
		SDL_DestroyWindow(Window);
		SDL_Quit();
		return false;
	}
	return true;
}


uint32 CSDLSetup::GetWindowFlags() const
{
	switch (WindowMode)
	{
	default:
	case EWindowMode::WindowPlayer:
		return SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_FOCUS;
		break;


	case EWindowMode::Windowed:
		return SDL_WINDOW_MAXIMIZED | SDL_WINDOW_INPUT_GRABBED;
		break;


	case EWindowMode::Fullscreen:
		return SDL_WINDOW_FULLSCREEN | SDL_WINDOW_INPUT_GRABBED;
		break;


	case EWindowMode::WindowBorderless:
		return SDL_WINDOW_BORDERLESS | SDL_WINDOW_FULLSCREEN | SDL_WINDOW_INPUT_GRABBED;
		break;
	}
}