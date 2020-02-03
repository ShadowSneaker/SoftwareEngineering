#pragma once
#include <CopiriteMath/Datatypes/Transform.h>
#include <SDL.h>


struct SImageInfo
{
	SDL_Surface* Surface;
	SDL_Texture* Texture;
	SVector2i ImageSize;
};



// the basic class for the image
class CImage
{
private:
	/// Properties

	// The size of the image (in pixels).
	SVector2i ImageSize;

public:
	// The location, rotaiton and scale of the image.
	STransform2 Transform;

	// Allows this image to be drawn on the screen.
	bool Enabled{ true };

	SVector2 Pivot;
	



public:

	/// Constructors

	// basic constructor
	CImage();

	//Destructor
	~CImage();

	

	///Functions

	// Sets a texture to this image using the inputted file path.
	// @param FilePath - The location in file of this image (start point is the soluttion folder).
	// @param UseDefaultPath - Should the file path start in a default directory of images.
	void SetTexture(std::string FilePath, bool UseDefaultPath = true);

	void SetColour(const uint8& Red, const uint8& Green, const uint8& Blue, const uint8& Alpha = 255);




	///Getters

	//Get the Image Width
	INLINE SVector2i GetSize() const { return ImageSize; }

	virtual INLINE SDL_Rect GetCell() const { SVector4{ 0.0f, ImageSize }.ToRect(); }

	virtual INLINE SVector2 GetWorldPivot() const { return (ImageSize * Transform.GetWorldScale()) / 2.0f; }

	INLINE SDL_Texture* GetTexture() const { return Texture; }
	INLINE SDL_Surface* GetSurface() const { return Surface; }

	SDL_RendererFlip GetFlip() const;

};

