#pragma once
#include <CopiriteMath/Datatypes/Vector.h>
#include <SDL.h>


struct SColour
{
	uint8 R{ 255 };
	uint8 G{ 255 };
	uint8 B{ 255 };
	uint8 A{ 255 };


public:
	/// Constructors

	SColour();

	SColour(const uint8& InR, const uint8& InG, const uint8& InB, const uint8& Alpha = 255);



	/// Conversions

	SDL_Color ToSDLColor()
	{
		return SDL_Color{ R, G, B, A };
	}
};



SColour::SColour()
{}


SColour::SColour(const uint8& InR, const uint8& InG, const uint8& InB, const uint8& Alpha)
	:R{ InR }, G{ InG }, B{ InB }, A{ Alpha }
{}


