
/**
Lewis Cleminson
DAC627 Software Engineering for Games: Professional Practice
AudioClip.cpp

*/


#include "AudioClip.h"



void AudioClip::setVolumn(int volumn)
{
    if (volumn < 0) volumn = 0;
    if (volumn > 10) volumn = 10;
    Mix_VolumeChunk(myClip, volumn * 12.8);
}

AudioClip::AudioClip(const char* filename)
{
    //Mix_Chunk* Sound = Mix_LoadWAV("Content/Audio/sound.wav");
    myClip = Mix_LoadWAV( filename);
    //Mix_Music* Sound2 = Mix_LoadMUS("Content/Audio/sound.wav");
    if (myClip == NULL) {
       // failed to load clip
    }
   

    setVolumn(5);
   // Mix_PlayChannel(-1, Sound, -1);
    //Mix_PlayMusic(Sound2, -1);


}

AudioClip::~AudioClip()
{
    Mix_FreeChunk(myClip);
    myClip = NULL;
}

Mix_Chunk* AudioClip::GetClip()
{
    return myClip;
}






