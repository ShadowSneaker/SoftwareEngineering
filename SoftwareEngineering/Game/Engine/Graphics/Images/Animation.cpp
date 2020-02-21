#include "Animation.h"
//#include "../../System/Time.h"



CAnimation::CAnimation()
	: CImage::CImage{}
{

}


CAnimation::~CAnimation()
{
	CImage::~CImage();
}


void CAnimation::Update()
{
	if (Playing)
	{
		Timer += Speed * 0.01f; //TTime::DeltaTime;
		FrameIndex = TMath::FloorInt(Timer) % TotalFrames;

		if (!Reversed && !Loop && FrameIndex == TotalFrames) Stop();
		else if (Reversed && !Loop && FrameIndex == 0) Stop();
	}
}


SDL_Rect CAnimation::GetCell() const
{
	SVector2 Scale{ Transform.GetWorldScale() };
	SVector4i Rect{ Cell.w * (int32)FrameIndex, Cell.h, int32(Cell.w * Scale[X]), int32(Cell.h * Scale[Y]) };
	return Rect.ToRect();
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
	Cell = (GetImageSize() / CellSize).ToRect();
	TotalFrames = (CellSize[X] * CellSize[Y]) - 1;
}