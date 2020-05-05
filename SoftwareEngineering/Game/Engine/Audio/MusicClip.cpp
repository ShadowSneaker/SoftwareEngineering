
/**
Lewis Cleminson
DAC627 Software Engineering for Games: Professional Practice
MusicClip.cpp

*/

#include "MusicClip.h"

void MusicClip::setVolumn(int volumn)
{
	if (volumn < 0) volumn = 0;
	if (volumn > 10) volumn = 10;
	Mix_VolumeMusic(volumn * 12.8);
	
}

MusicClip::MusicClip(const char* filename)
{
	myClip =  Mix_LoadMUS(filename);
	
}

MusicClip::~MusicClip()
{
	Mix_FreeMusic(myClip);
	myClip = NULL;
}

Mix_Music* MusicClip::GetClip()
{
	return myClip;
}
