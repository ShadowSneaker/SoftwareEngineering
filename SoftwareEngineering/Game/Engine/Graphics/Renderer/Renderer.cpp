#include "Renderer.h"
#include <algorithm>



CRenderer* CRenderer::Instance{ nullptr };



CRenderer::CRenderer()
{
	if (!Instance)
	{
		Setup = new CSDLSetup();
		Setup->Initialize();
		Instance = this;
	}
}


CRenderer::~CRenderer()
{
	DeleteAllImages();
	DeleteAllTextures();
	delete Setup;
}

// Clears the renderer within object
void CRenderer::Clear()
{
	SDL_RenderClear(Setup->GetRenderer());
}

// Presents the renderer window
void CRenderer::Present()
{
	SDL_RenderPresent(Setup->GetRenderer());
}

// Removes all images from the renderer object
void CRenderer::DeleteAllImages()
{
	while (!Images.empty())
	{
		if (Images.back())
		{
			delete Images.back();
		}
		Images.pop_back();
	}
}

// Removes all textures from this object
void CRenderer::DeleteAllTextures()
{
	for (auto i = Textures.begin(); i != Textures.end(); ++i)
	{
		if (i->second.Texture) SDL_DestroyTexture(i->second.Texture);
		if (i->second.Surface) SDL_FreeSurface(i->second.Surface);
	}
}

// Draws all stored images to the screen then presents
// @Note does not cull
void CRenderer::DrawAllImages() 
{
	std::sort(Images.begin(), Images.end(), IMAGE_ZORDER_SORTER());

	Clear();
	for (CImage* Image : Images)
	{
		if (Image->Enabled)
		{
			Image->Update();
			DrawImage(Image);
		}
	}
	Present();
}

// Draws inputted image to screen then presents
// @param Image - points to the image being inputted
void CRenderer::DrawImage(CImage* Image) const
{
	SDL_Rect Cell{ Image->GetCell() };
	SVector2 Pivot{ Image->Pivot };
	
	STransform2 Local{ Image->Transform };
	Local.Location -= Pivot;

	STransform2 WorldTransform{ Local.GetWorldTransform() };

	SDL_FRect Rect;
	Rect.x = WorldTransform.Location[X];
	Rect.y = WorldTransform.Location[Y];
	Rect.w = Cell.w * WorldTransform.Scale[X];
	Rect.h = Cell.h * WorldTransform.Scale[Y];

	SDL_RenderCopyExF(Setup->GetRenderer(), Image->GetTexture(), &Cell, &Rect, (double)WorldTransform.Rotation, &Pivot.ToFPoint(), Image->GetFlip());
}


bool CRenderer::AddTexture(const std::string& FilePath, const bool& UseDefaultPath)
{
	std::string Path{ GetPath(FilePath, UseDefaultPath) };
	if (!Textures.count(Path))
	{
		SImageInfo ImageInfo;
		ImageInfo.Surface = IMG_Load(Path.c_str());
		if (!ImageInfo.Surface)
		{
			std::cout << "Failed to create surface from file: " + Path << std::endl;
			return false;
		}

		ImageInfo.Texture = SDL_CreateTextureFromSurface(Setup->GetRenderer(), ImageInfo.Surface);
		if (!ImageInfo.Texture)
		{
			std::cout << "Failed to create texture from file: " + Path << std::endl;
			SDL_FreeSurface(ImageInfo.Surface);
			return false;
		}

		SDL_QueryTexture(ImageInfo.Texture, NULL, NULL, &ImageInfo.ImageSize[X], &ImageInfo.ImageSize[Y]);
		Textures.insert(std::pair<std::string, SImageInfo>(Path, ImageInfo));
	}
	return true;
}


void CRenderer::SetImage(CImage* Image, const std::string& FilePath, const bool& UseDefaultPath)
{
	std::string Path{ GetPath(FilePath, UseDefaultPath) };

	if (!Textures.count(Path))
	{
		if (!AddTexture(FilePath, UseDefaultPath))
		{
			throw std::runtime_error("Texture failed to be created");
		}
	}
	SImageInfo Info{ Textures[Path] };
	Image->SetImage(Info, Path);
}


void CRenderer::AddImage(CImage* Image)
{
	if (!ContainsImage(Image))
	{
		Images.push_back(Image);
	}
}


void CRenderer::RemoveImage(CImage* Image)
{
	for (uint i = 0; i < Images.size(); ++i)
	{
		if (Images[i] == Image)
		{
			Images.erase(Images.begin() + i);
		}
	}
}


void CRenderer::DeleteImage(CImage* Image)
{
	RemoveImage(Image);
	delete Image;
}


bool CRenderer::ContainsImage(const CImage* Image)
{
	for (uint i = 0; i < Images.size(); ++i)
	{
		if (Images[i] == Image) return true;
	}
	return false;
}


void CRenderer::SetBackgroundColour(const SColour& Colour)
{
	SDL_SetRenderDrawColor(Setup->GetRenderer(), Colour.R, Colour.G, Colour.B, Colour.A);
}


void CRenderer::SetBackgroundColour(const uint8& Red, const uint8& Green, const uint8& Blue, const uint8& Alpha)
{
	SetBackgroundColour(SColour{ Red, Green, Blue, Alpha });
}


void CRenderer::SetBackgroundColour(const SDL_Color& Colour)
{
	SetBackgroundColour(SColour{ Colour });
}


SImageInfo CRenderer::GetImage(const std::string& Path)
{
	if (!Textures.count(Path))
	{
		AddTexture(Path, false);
	}

	return Textures[Path];
}