#include "Animation.h"
#include "../../System/Time.h"



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
		//float oldframe = FrameIndex;
		//Timer += Speed * TTime::DeltaTime;
		FrameIndex = TMath::FloorInt((TTime::Time - PauseTime ) * Speed * ((IsReversed()) ? -1.0f : 1.0f)) % TotalFrames;

		//printf("%f\n", (TTime::Time - PauseTime) * Speed * ((IsReversed()) ? -1.0f : 1.0f));
		//if (oldframe != FrameIndex)
		//	AnimationTestFunction();


		if (!IsReversed() && !Loop && FrameIndex == TotalFrames) Stop();
		else if (IsReversed() && !Loop && FrameIndex == 0) Stop();

		
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
	if (!Playing)
	{
		float Temp = PauseTime;
		PauseTime = TTime::Time - Temp;
		if (IsReversed()) Reverse();
		Playing = true;
	}
}


void CAnimation::Stop()
{
	Playing = false;
}


void CAnimation::Reverse()
{
	//Speed *= -1.0f;
	float Temp = (FrameIndex) / -Speed;
	PauseTime = TTime::Time - Temp;

	Reversed = !Reversed;
}


void CAnimation::PlayFromStart()
{
	PauseTime = TTime::Time;
	Reversed = false;
	Play();
}


void CAnimation::ReverseFromEnd()
{
	//Speed *= -1.0f;
	//FrameIndex = TotalFrames;

	Reversed = true;
	float Temp = (TotalFrames) / -Speed;
	PauseTime = TTime::Time - Temp;
	Playing = true;
}


void CAnimation::SetCellCount(const uint& Rows, const uint& Columns)
{
	CellSize[X] = Columns;
	CellSize[Y] = Rows;

	Cell.w = GetImageSize()[X] / Columns;
	Cell.h = GetImageSize()[Y] / Rows;
	TotalFrames = Columns * Rows;
}


void CAnimation::SetCellCount(const SVector2i& InCells)
{
	CellSize = InCells;
	Cell.w = GetImageSize()[X] / CellSize[X];
	Cell.h = GetImageSize()[Y] / CellSize[Y];
	TotalFrames = (CellSize[X] * CellSize[Y]);
}

void CAnimation::AnimationTestFunction()
{
	printf("The Current Frame the animation is on --> Frame: %i\n", FrameIndex);
}