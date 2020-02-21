#include "Animation.h"
//#include "../../System/Time.h"



CAnimation::CAnimation()
	: CImage::CImage{}
{
	Cell.x = 0;
	Cell.y = 0;
	Cell.w = ImageSize[X];
	Cell.h = ImageSize[Y];
	TotalFrames = 1;
	FrameIndex = 0;
	Timer = 0.0f;
}


CAnimation::~CAnimation()
{
	CImage::~CImage();
}


void CAnimation::Update()
{
	if (Playing)
	{
		Timer += Speed * 0.5f; //TTime::DeltaTime;
		FrameIndex = TMath::FloorInt(Timer) % TotalFrames;

		if (!Reversed && !Loop && FrameIndex == TotalFrames) Stop();
		else if (Reversed && !Loop && FrameIndex == 0) Stop();
	}
}


SDL_Rect CAnimation::GetCell() const
{
	SVector2 Scale{ Transform.GetWorldScale() };
	SVector4i Rect{ Cell.w * (int32)FrameIndex, Cell.y, int32(Cell.w * Scale[X]), int32(Cell.h * Scale[Y]) };
	return Rect.ToRect();
}


void CAnimation::SetImage(const std::string& Path)
{
	CImage::SetImage(Path);

	Cell.x = 0;
	Cell.y = 0;

	
	if (CellSize[X] != 0.0f) Cell.w = GetImageSize()[X] / CellSize[X];
	if (CellSize[Y] != 0.0f) Cell.h = GetImageSize()[Y] / CellSize[Y];
	
}


void CAnimation::Play()
{
	Reversed = false;
	Playing = true;
}


void CAnimation::Stop()
{
	Playing = false;
}


void CAnimation::Reverse()
{
	Reversed = !Reversed;
	Playing = true;
}


void CAnimation::PlayFromStart()
{
	FrameIndex = 0;
	Play();
}


void CAnimation::ReverseFromEnd()
{
	FrameIndex = TotalFrames;
	Reversed = true;
	Playing = true;
}


void CAnimation::SetCellCount(const uint& Rows, const uint& Columns)
{
	CellSize[X] = Columns;
	CellSize[Y] = Rows;

	Cell.w = GetImageSize()[X] / Columns;
	Cell.h = GetImageSize()[Y] / Rows;
	TotalFrames = Columns * Rows - 1;
}


void CAnimation::SetCellCount(SVector2i InCells)
{
	CellSize = InCells;
	Cell.w = GetImageSize()[X] / CellSize[X];
	Cell.h = GetImageSize()[Y] / CellSize[Y];
	TotalFrames = (CellSize[X] * CellSize[Y]) - 1;
}