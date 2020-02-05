#pragma once
#pragma warning(disable : 26812)

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
	CSDLSetup* Setup;

	// A reference to all loaded textures.
	// Used to keep one reference of all texture types.
	std::map<std::string, SImageInfo> Textures;

	// A list of all stored image objects to render.
	std::vector<CImage*> Images;


public:
	/// Constructors

	// Constructor, Default.
	CRenderer();

	// Destructor
	~CRenderer();



private:
	/// Functions

	// Removes all images stored from this object.
	void DeleteAllImages();

	// Removes all textures stored in this object.
	void DeleteAllTextures();

public:
	// Clears the window.
	void Clear();

	// Presents the current frame to the window.
	void Present();


	// Draws all stored images on to the screen then presents it.
	// @Note - Does not cull any images.
	void DrawAllImages();

	// Draws the inputted image to the screen.
	// @param Image - A reference to the image that should be drawn.
	void DrawImage(CImage* Image) const;

	void AddImage(const std::string& FilePath);


	/// Setters



	/// Getters
};