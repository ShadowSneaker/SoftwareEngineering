#pragma once
#include <CopiriteMath/Datatypes/Transform.h>
#include "../Colour.h"


struct SImageInfo
{
	SDL_Surface* Surface{ nullptr };
	SDL_Texture* Texture{ nullptr };
	SVector2i ImageSize{ 0 };
};



// the basic class for the image.
class CImage
{
private:
	/// Properties

	// Checks if this image is currently being deleted.
	bool IsDestroying{ false };

	// A reference to the texture surface this image uses.
	SDL_Surface* Surface{ nullptr };

	// A reference to the texture this image has.
	SDL_Texture* Texture{ nullptr };

	// The multiplied colour applied on the image.
	SColour Colour{ SColour::White() };

protected:
	// The size of the image (in pixels).
	SVector2i ImageSize;

	// The location in files where this image was created.
	std::string FilePath{""};

public:
	// The location, rotaiton and scale of the image.
	STransform2 Transform;

	// Allows this image to be drawn on the screen.
	bool Enabled{ true };

	// The location this image is translated, rotated and scaled from.
	SVector2 Pivot;
	
	// Determiens what layer this image is drawn on.
	// The higher the number, the further up the image is drawn.
	int32 ZOrder{ 0 };

	// If true, the image will be flipped along the X axis.
	bool FlipX{ false };

	//If true, the image will be flipped along the Y axis.
	bool FlipY{ false };



public:
	/// Constructors

	// Constructor, Default.
	CImage();

	// Destructor.
	~CImage();



	/// Overridables

	// Updates any image updates that need to occure before the image is drawn.
	virtual void Update() {}

	

	/// Functions

	// Sets a texture to this image using the inputted information.
	// @param Info - The image info to use.
	// @param FilePath - The file path to this texture.
	void SetImage(const SImageInfo& Info, const std::string& Path);

	// Sets a texture to this image.
	// @param Path - The file path to this texture.
	virtual void SetImage(const std::string& Path);

	// Sets the colour multiplied on this image.
	// @param Red - The red component this image should be multiplied with.
	// @param Green - The green component this image should be multiplied with.
	// @param Blue - The blue component this image should be multiplied with.
	// @param Alpha -The alpha component this image should be multiplied with.
	void SetColour(const uint8& Red, const uint8& Green, const uint8& Blue, const uint8& Alpha = 255);

	// Sets the colour multiplied on this image.
	// @param Colour - The red, green, blue and alpha components this image shoudl be multiplied with.
	void SetColour(const SColour& Colour);

	// Sets the colour multiplied on this image.
	// @param Colour - The red, green, blue and alpha components this image shoudl be multiplied with.
	void SetColour(const SDL_Color& Colour);

	//function used for testing the images location
	void TestImageLocation(float ImageLocationX, float ImageLocationY);

	// a function that tests the images colour against the original
	void TestImageColour(const uint8& Red, const uint8& Green, const uint8& Blue);

	/// Getters

	// Returns the size of this image (in pixels).
	INLINE SVector2i GetSize() const { return ImageSize; }

	// Returns the size of this image's displayed cell (in pixels).
	virtual SDL_Rect GetCell() const { return SVector4{ 0.0f, ImageSize.ToFloat() }.ToRect(); }

	// Returns the location of this image's pivot point in worldspace.
	virtual INLINE SVector2 GetWorldPivot() const { return (ImageSize.ToFloat() * Transform.GetWorldScale()) / 2.0f; }

	// Returns the size of this image (in pixels).
	INLINE SVector2i GetImageSize() const { return ImageSize; }

	// Returns the size of this image after scaling (in pixels).
	INLINE SVector2 GetDisplaySize() const { return ImageSize.ToFloat() * Transform.GetWorldScale(); }

	// Returns the colour that is being multiplied onto this image.
	INLINE SColour GetColour() const { return Colour; }

	// Returns the center point of this image.
	INLINE SVector2 GetImageCenter() const { return (ImageSize.ToFloat() * Transform.GetWorldScale()) / 2.0f; }
	
	// Returns the file location to this image.
	INLINE std::string GetFilePath() const { return FilePath; }

	// Returns a reference to the texture this image uses.
	INLINE SDL_Texture* GetTexture() const { return Texture; }

	// Returns a reference to the surface this image uses.
	INLINE SDL_Surface* GetSurface() const { return Surface; }

	// Returns if this object is currently being removed from memory.
	INLINE bool GetDestroying() const { return IsDestroying; }

	// Get the image flipped data.
	SDL_RendererFlip GetFlip() const;

};



// Sort filter used to sort a vector of images to get their ZOrder.
struct IMAGE_ZORDER_SORTER
{
	INLINE bool operator()(const CImage* Image1, const CImage* Image2) const
	{
		return (Image1->ZOrder < Image2->ZOrder);
	}
};