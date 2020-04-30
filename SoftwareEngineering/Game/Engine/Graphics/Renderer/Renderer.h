#pragma once
#pragma warning(disable : 26812)

#include "SDLSetup.h"
#include "../Images/Image.h"
#include <map>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include "../..//System/Camera.h"


// 
class CRenderer
{
public:
	/// Static Properties

	// The pointer refernce to the Renderer.
	static CRenderer* Instance;



private:
	/// Properties

	// The setup object of SDL.
	CSDLSetup* Setup{ nullptr };

	// A reference to all loaded textures.
	// Used to keep one reference of all texture types.
	std::map<std::string, SImageInfo> Textures;

	// A list of all stored image objects to render.
	std::vector<CImage*> Images;

	// A refernce to the camera.
	CCamera* MainCamera{ nullptr };



public:
	/// Constructors

	// Constructor, Default.
	CRenderer();

	// Destructor.
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

	// Sets the colour the window refreshes with.
	// @param Colour - The red, green and blue colour to set the window.
	void SetBackgroundColour(const SColour& Colour);

	// Sets the colour the window refreshes with.
	// @param Red - The red component to set the background with.
	// @param Green - The green component to set the background with.
	// @param Blue - The blue component to set the background with.
	// @param Alpha - The alpha component to set the background with.
	void SetBackgroundColour(const uint8& Red, const uint8& Green, const uint8& Blue, const uint8& Alpha = 255);

	// Sets the colour the window refreshes with.
	// @param Colour - The red, green and blue colour to set the window.
	void SetBackgroundColour(const SDL_Color& Colour);



	/// Setters

	// Sets the reference to the main camera.
	// @param Camera - The reference to the camera to set as the main camera.
	void SetMainCamera(CCamera* Camera);


	// a test function used to test the images surface for pixel information
	void RenderImagePixelTest(CImage* TheTestImage, int x, int y);


private:
	/// Getters

	// Returns the file built filepath of an inputted file.
	INLINE std::string GetPath(const std::string& Path, const bool& UseDefaultPath = true) const { return std::string{ (UseDefaultPath) ? "" + Path : Path }; }

public:
	// Returns the image info of a loaded image.
	// @note - The images is not returned if the image has not been loaded yet.
	// @param - The file path to the image to get the info of.
	SImageInfo GetImage(const std::string& Path);


	// Returns the size of the window.
	INLINE SVector2i GetWindowSize() const { return Setup->WindowSize; }

	// Returns the size of the main monitor.
	INLINE SVector2i GetScreenSize() const { return SVector2i{ Setup->GetDisplayMode().w, Setup->GetDisplayMode().h }; }

	// Returns the base information of the main monitor.
	INLINE SDL_DisplayMode GetScreenInfo() const { return Setup->GetDisplayMode(); }

	// returns the SDL Renderer
	INLINE SDL_Renderer* GetSDLRenderer() const { return Setup->GetRenderer(); }
};