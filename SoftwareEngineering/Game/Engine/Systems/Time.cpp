#include "Time.h"
#include <SDL_timer.h>



float TTime::DeltaTime{ 0.0f };
float TTime::TimeScale{ 1.0f };



TTime::TTime()
{
	CurrentFrame = SDL_GetPerformanceCounter();
}



void TTime::Update()
{
	LastFrame = CurrentFrame;
	CurrentFrame = SDL_GetPerformanceCounter();
	DeltaTime = (float(CurrentFrame - LastFrame) / float(SDL_GetPerformanceFrequency())) * TimeScale;
}