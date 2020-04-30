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


void CRenderer::Clear()
{
	SDL_RenderClear(Setup->GetRenderer());
}


void CRenderer::Present()
{
	SDL_RenderPresent(Setup->GetRenderer());
}


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


void CRenderer::DeleteAllTextures()
{
	for (auto i = Textures.begin(); i != Textures.end(); ++i)
	{
		if (i->second.Texture) SDL_DestroyTexture(i->second.Texture);
		if (i->second.Surface) SDL_FreeSurface(i->second.Surface);
	}
}


void CRenderer::DrawAllImages()
{
	std::sort(Images.begin(), Images.end(), IMAGE_ZORDER_SORTER());

	for (CImage* Image : Images)
	{
		if (Image->Enabled)
		{
			if (Image->GetTexture() != nullptr && Image->GetSurface() != nullptr) {
				Image->Update();
				DrawImage(Image);
			}
		}
	}
	Present();
}


void CRenderer::DrawImage(CImage* Image) const
{
	SDL_Rect Cell{ Image->GetCell() };
	SVector2 Pivot{ Image->Pivot };

	STransform2 Local{ Image->Transform };
	Local.Location -= Pivot;

	STransform2 WorldTransform{ Local.GetWorldTransform() };

	SDL_FRect Rect;
	Rect.x = WorldTransform.Location[X] - MainCamera->GetCameraX() + MainCamera->GetCameraOffSetX();
	Rect.y = WorldTransform.Location[Y] - MainCamera->GetCameraY() + MainCamera->GetCameraOffSetY();
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

void CRenderer::SetMainCamera(CCamera* TheMainCamera)
{
	MainCamera = TheMainCamera;
}


void CRenderer::RenderImagePixelTest(CImage* TheImage, int x, int y)
{
	SDL_Surface* TempSurface = TheImage->GetSurface();


	SImageInfo Info{ CRenderer::Instance->GetImage("Content/Images/HappyBoi.png") };

	SDL_Surface* SurfaceToTest = Info.Surface;

	Uint32 temp, pixel, pixelTest;
	Uint8 Red, Green, Blue, Alpha;

	Uint8 Red2, Green2, Blue2, Alpha2;

	Uint8 index;
	SDL_Color* colour;

	SDL_PixelFormat* pixelformat;
	pixelformat = TempSurface->format;

	SDL_PixelFormat* pixelformattest;
	pixelformattest = TempSurface->format;


	for (int i = 0; i <= 32; i++)
	{

		for (int j = 0; j <= 32; j++)
		{

			SDL_LockSurface(TempSurface);
			pixel = *((Uint32*)TempSurface->pixels) + (i * TempSurface->pitch) + (j * pixelformat->BytesPerPixel);
			SDL_UnlockSurface(TempSurface);

			SDL_LockSurface(SurfaceToTest);
			pixelTest = *((Uint32*)SurfaceToTest->pixels) + (i * SurfaceToTest->pitch) + (j * pixelformattest->BytesPerPixel);
			SDL_UnlockSurface(SurfaceToTest);

			temp = pixel & pixelformat->Rmask;
			temp = temp >> pixelformat->Rshift;
			temp = temp << pixelformat->Rloss;
			Red = (Uint8)temp;

			temp = pixel & pixelformat->Gmask;
			temp = temp >> pixelformat->Gshift;
			temp = temp << pixelformat->Gloss;
			Green = (Uint8)temp;

			temp = pixel & pixelformat->Bmask;
			temp = temp >> pixelformat->Bshift;
			temp = temp << pixelformat->Bloss;
			Blue = (Uint8)temp;


			temp = pixelTest & pixelformat->Rmask;
			temp = temp >> pixelformat->Rshift;
			temp = temp << pixelformat->Rloss;
			Red2 = (Uint8)temp;

			temp = pixelTest & pixelformat->Gmask;
			temp = temp >> pixelformat->Gshift;
			temp = temp << pixelformat->Gloss;
			Green2 = (Uint8)temp;

			temp = pixelTest & pixelformat->Bmask;
			temp = temp >> pixelformat->Bshift;
			temp = temp << pixelformat->Bloss;
			Blue2 = (Uint8)temp;

			printf("Pixel Colour - > R: %d, G: %d, B:%d\n", Red, Green, Blue);
			printf("Pixel Colour of stored image - > R: %d, G: %d, B:%d\n", Red2, Green2, Blue2);
		}
	}


	//for (int i = 0; i <= 40; i++)
	//{
	//	Uint8* TargetPixel = (Uint8*)TempSurface->pixels + (y + i) * TempSurface->pitch + (x + i) * sizeof * TargetPixel;
	//
	//
	//	if (TargetPixel == (Uint8*)255)
	//	{
	//		std::cout << "Confirmed Pixel drawing" << std::endl;
	//	}
	//	else
	//	{
	//		std::cout << "pixel not in that position" << std::endl;
	//	}
	//}
}