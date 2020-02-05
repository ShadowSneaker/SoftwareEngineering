#include "Renderer.h"



CRenderer::CRenderer()
{
	Setup = new CSDLSetup();
	Setup->Initialize();
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
	Clear();
	for (CImage* Image : Images)
	{
		if (Image->Enabled)
		{
			DrawImage(Image);
		}
	}
	Present();
}


void CRenderer::DrawImage(CImage* Image) const
{
	STransform2 WorldTransform{ Image->Transform.GetWorldTransform() };
	SDL_Rect Cell{ Image->GetCell() };
	SVector2 Pivot{ Image->Pivot };

	SDL_FRect Rect;
	Rect.x = WorldTransform.Location[X] - Pivot[X];
	Rect.y = WorldTransform.Location[Y] - Pivot[Y];
	Rect.w = Image->GetCell().x * WorldTransform.Scale[X];
	Rect.h = Image->GetCell().y * WorldTransform.Scale[Y];

	SDL_RenderCopyExF(Setup->GetRenderer(), Image->GetTexture(), &Cell, &Rect, WorldTransform.Rotation, &Image->Pivot.ToFPoint(), Image->GetFlip());
}


void CRenderer::AddImage(const std::string& FilePath)
{
	std::string Path{ FilePath };
	if (!Textures.count(Path))
	{
		SImageInfo ImageInfo;
		ImageInfo.Surface = IMG_Load(Path.c_str());
	}
}