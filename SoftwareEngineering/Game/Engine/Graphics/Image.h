#pragma once
#include <CopiriteMath/Datatypes/Transform.h>
#include "Colour.h"


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


	SDL_Surface* Surface{ nullptr };
	SDL_Texture* Texture{ nullptr };
	SColour Colour{ SColour{} };

protected:
	// The size of the image (in pixels).
	SVector2i ImageSize;

	std::string FilePath{""};

public:
	// The location, rotaiton and scale of the image.
	STransform2 Transform;

	// Allows this image to be drawn on the screen.
	bool Enabled{ true };

	SVector2 Pivot;
	
	int32 ZOrder{ 0 };

	bool FlipX{ false };

	bool FlipY{ false };





public:

	/// Constructors

	// basic constructor
	CImage();

	//Destructor
	~CImage();



	/// Overridables

	virtual void Update() {}

	

	///Functions

	// Sets a texture to this image using the inputted information.
	// @param Info - the image info to use.
	// @param FilePath - The file path to this texture.
	void SetImage(const SImageInfo& Info, const std::string& Path);

	void SetColour(const uint8& Red, const uint8& Green, const uint8& Blue, const uint8& Alpha = 255);




	///Getters

	//Get the Image Width
	INLINE SVector2i GetSize() const { return ImageSize; }

	// 
	virtual INLINE SDL_Rect GetCell() const { return SVector4{ 0.0f, ImageSize.ToFloat() }.ToRect(); }

	// 
	virtual INLINE SVector2 GetWorldPivot() const { return (ImageSize.ToFloat() * Transform.GetWorldScale()) / 2.0f; }

	// 
	INLINE SVector2i GetImageSize() const { return ImageSize; }

	// 
	INLINE SVector2 GetDisplaySize() const { return ImageSize.ToFloat() * Transform.GetWorldScale(); }

	// 
	INLINE SColour GetColour() const { return Colour; }

	// 
	INLINE SVector2 GetImageCenter() const { return (ImageSize.ToFloat() * Transform.GetWorldScale()) / 2.0f; }
	
	// 
	INLINE std::string GetFilePath() const { return FilePath; }

	// 
	INLINE SDL_Texture* GetTexture() const { return Texture; }

	// 
	INLINE SDL_Surface* GetSurface() const { return Surface; }

	// 
	SDL_RendererFlip GetFlip() const;

};

