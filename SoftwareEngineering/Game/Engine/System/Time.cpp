#include "Time.h"
#include <SDL_timer.h>



float TTime::DeltaTime{ 0.0f };
float TTime::TimeScale{ 1.0f };
float TTime::Time{ 0.0f };



TTime::TTime()
{
	Current = SDL_GetPerformanceCounter();
}



void TTime::Update()
{
	Previous = Current;
	Current = SDL_GetPerformanceCounter();


	float DT = (float)((Current - Previous) * 1000.0f / (float)SDL_GetPerformanceFrequency());
	DeltaTime = DT * TimeScale;

	Time += DT;
}