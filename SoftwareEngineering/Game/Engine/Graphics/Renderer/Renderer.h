#pragma once
#pragma warning(disable : 26812)

#include "SDLSetup.h"
#include "../Images/Image.h"
#include <map>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>



// 
class CRenderer
{
public:
	/// Static Properties

	static CRenderer* Instance;



private:
	/// Properties
	CSDLSetup* Setup{ nullptr };

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

	// Loads a texture file and inserts it into this object.
	// @param FilePath - The path to the file.
	// @param UseDefaultPath - Should the root directory be the default location of textures.
	// @return - Returns true if the file already exists or was successfully created.
	bool AddTexture(const std::string& FilePath, const bool& UseDefaultPath = true);

	// Sets a texture onto an image.
	// @param Image - The image object to apply the texture on to.
	// @param FilePath - The location in files of the texture.
	// @param UseDefaultPath - Should the root directory be the default location of textures.
	void SetImage(CImage* Image, const std::string& FilePath, const bool& UseDefaultPath = true);

	// Adds an image to this object.
	// @param Image - The reference to the image to add.
	void AddImage(CImage* Image);

	// Removes an image from this object.
	// @param Image - The reference to the image to remove.
	void RemoveImage(CImage* Image);

	// Safely remvoes and deletes the inputted image from this object.
	// @note - Inputted images that are not stored in this object will still be deleted.
	// @param Image - The reference to the image to delete.
	void DeleteImage(CImage* Image);

	// Checks to see if the images has already been added to this object.
	// @param Image - The reference to the image to add.
	// @return - Returns true if the image already exists.
	bool ContainsImage(const CImage* Image);




	/// Setters

	void SetBackgroundColour(const SColour& Colour);
	void SetBackgroundColour(const uint8& Red, const uint8& Green, const uint8& Blue, const uint8& Alpha = 255);
	void SetBackgroundColour(const SDL_Color& Colour);



private:
	/// Getters

	// Returns the file built filepath of an inputted file.
	INLINE std::string GetPath(const std::string& Path, const bool& UseDefaultPath = true) const { return std::string{ (UseDefaultPath) ? "" + Path : Path }; }


public:
	SImageInfo GetImage(const std::string& Path);


	// Returns the size of the window.
	INLINE SVector2i GetWindowSize() const { Setup->WindowSize; }
};