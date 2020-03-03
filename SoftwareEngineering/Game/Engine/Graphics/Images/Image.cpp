#include "Image.h"
#include "../Renderer/Renderer.h"



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


void CImage::SetImage(const std::string& Path)
{
	SImageInfo Info{ CRenderer::Instance->GetImage(Path) };
	Surface = Info.Surface;
	Texture = Info.Texture;
	ImageSize = Info.ImageSize;
	FilePath = Path;
	Pivot = GetImageCenter();
}


void CImage::SetColour(const uint8& Red, const uint8& Green, const uint8& Blue, const uint8& Alpha)
{
	Colour.R = Red;
	Colour.G = Green;
	Colour.B = Blue;
	Colour.A = Alpha;
	
	SDL_SetTextureColorMod(Texture, Colour.R, Colour.G, Colour.B);
	SDL_SetTextureAlphaMod(Texture, Colour.A);
}

void CImage::SetColour(const SColour& Colour)
{
	SDL_SetTextureColorMod(Texture, Colour.R, Colour.G, Colour.B);
	SDL_SetTextureAlphaMod(Texture, Colour.A);
}

void CImage::SetColour(const SDL_Color& Colour)
{
	SDL_SetTextureColorMod(Texture, Colour.r, Colour.g, Colour.b);
	SDL_SetTextureAlphaMod(Texture, Colour.a);
}


SDL_RendererFlip CImage::GetFlip() const
{
	uint32 Flip = SDL_FLIP_NONE;
	if (FlipX) Flip += SDL_FLIP_HORIZONTAL;
	if (FlipY) Flip += SDL_FLIP_VERTICAL;
	return SDL_RendererFlip(Flip);
}

