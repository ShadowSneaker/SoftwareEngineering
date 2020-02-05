#include "Image.h"

// the defualt constructor for the image
CImage::CImage()
{

}

// default Destructor
CImage::~CImage()
{

}


void CImage::SetImage(const SImageInfo& Info, const std::string& Path)
{
	Surface = Info.Surface;
	Texture = Info.Texture;
	ImageSize = Info.ImageSize;
	FilePath = Path;
	Pivot = GetImageCenter();
}


void CImage::SetColour(const uint8& Red, const uint8& Green, const uint8& Blue, const uint8& Alpha)
{

}


SDL_RendererFlip CImage::GetFlip() const
{
	uint32 Flip = SDL_FLIP_NONE;
	if (FlipX) Flip += SDL_FLIP_HORIZONTAL;
	if (FlipY) Flip += SDL_FLIP_VERTICAL;
	return SDL_RendererFlip(Flip);
}