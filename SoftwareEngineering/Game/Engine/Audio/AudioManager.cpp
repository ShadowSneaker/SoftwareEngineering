
/**
Lewis Cleminson
DAC627 Software Engineering for Games: Professional Practice
AudioManager.cpp

*/


#include "AudioManager.h"

void AudioManager::resumeMusic()
{
    Mix_ResumeMusic();
}

/**
Perminantly stop the current playing music track.
*/
void AudioManager::stopMusic()
{
    Mix_HaltMusic();
    musicPlaying = false;
}

bool AudioManager::isClipPlaying(AudioClip* clip)
{

    for (int i = 0; i < m_maxChannels; i++) {
        if (Mix_Playing(i)) {
            if (Mix_GetChunk(i) == clip->GetClip()) return true;
       }
    }


    return false;
}



AudioManager::AudioManager()
{
   // Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    init(); //initialise audio system


    Mix_AllocateChannels(16); //set number of channels
    m_maxChannels = 16;
    Mix_VolumeMusic(500);
}

AudioManager::~AudioManager()
{
    Mix_Quit();
}


/**
Plays a single-fire Audioclip.
*/
void AudioManager::Play(AudioClip* clip, bool loop )
{
    if (SfxMute) return;
    int looping = 0;
    if (loop) looping--;
   int channel =  Mix_PlayChannel(-1, clip->GetClip(), looping);
  
}


/**
Plays a music track on a constant loop until stopped.
*/
void AudioManager::Play(MusicClip* clip)
{
    Mix_PlayMusic(clip->GetClip(), -1);
    musicPlaying = true;
}


/**
AudioManager Initialization. Creates a default Audio Mixer.
*/
bool AudioManager::init()
{

 if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1) {
        //then failed
     return false;
    }

    return true;
}


/**
Stop a currently playing AudioClip.
*/
void AudioManager::stopClip(AudioClip* clip)
{
    Mix_Chunk* aud = clip->GetClip();
    for (int i = 0; i < MIX_CHANNELS; i++) {
        if (Mix_GetChunk(i) == aud) Mix_HaltChannel(i);
       // i++;
    }


}
 

/**
Returns true if music is currently playing.
*/
bool AudioManager::isMusicPlaying()
{
    return musicPlaying;
}

bool AudioManager::isSfxMuted()
{
    return SfxMute;
}

/**
Pauses / resumes current music track.
*/
void AudioManager::toggleMusic()
{
    if (musicPlaying) Mix_PauseMusic();
    else Mix_ResumeMusic();
    musicPlaying = !musicPlaying;
}

void AudioManager::toggleSfx()
{
    SfxMute = !SfxMute;

        for (int i = 0; i < MIX_CHANNELS; i++) {
            if (SfxMute) Mix_Volume(i, 0);
            else Mix_Volume(i, 128);
           }

    
}
