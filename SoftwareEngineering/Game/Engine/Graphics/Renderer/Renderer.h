#pragma once
#include "SDLSetup.h"
#include "..\\Image.h"
#include <map>
#include <vector>
#include <SDL.h>

// 
class CRenderer
{
private:
	/// Properties
	CSDLSetup* TheSetUp;

	//
	std::map<std::string, SDL_Texture> ImageTextures;

	//
	std::vector<CImage*> Images;


public:
	/// Constructors

	// Constructor, Default.
	CRenderer();

	// Destructor
	~CRenderer();



	/// Functions

	//
	void DrawAllImages();

	// Param:
	// Name is the file path from the image class to determine the texture from the map above
	// TheImage is the image that is going to be used to draw at the screen
	void DrawImage(CImage* TheImage, std::string Name);


	/// Setters



	/// Getters
};