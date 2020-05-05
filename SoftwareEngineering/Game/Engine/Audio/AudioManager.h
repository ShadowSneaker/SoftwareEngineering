
/**
Lewis Cleminson
DAC627 Software Engineering for Games: Professional Practice
AudioManager.h

*/


#include <SDL.h>
#include <SDL_audio.h>
#include <SDL_mixer.h>
#include "AudioClip.h"
#include "MusicClip.h"

#pragma once



class AudioManager
{
private:

    bool musicPlaying;
    bool SfxMute;
    int m_maxChannels;

public:
  
    /**
Initialized the SDL mixer
*/
    bool init();
  
    /**
Stops a playing audio clip, including any subsequent loops.
*/
    void stopClip(AudioClip* clip);

    /**
   Returns true if music is currently playing
   */
    bool isMusicPlaying();
    
    /**
Returns true if Sfx is currently muted.
*/
    bool isSfxMuted();
  
    /**
Toggles the music, pausing and unpausing each call.
*/
    void toggleMusic();
    
    /**
Toggles the Sfx, muting and unmuting each call.
*/
  void toggleSfx();
  
  /**
  Resumes playing any paused music
  */
  void resumeMusic();
    
  /**
Stops music from playing. Music stopped cannot be later resumed, but must be restarted.
*/
  void stopMusic();

  /**
  Returns true if the audioclip is playing.
  */
  bool isClipPlaying(AudioClip* clip);


  
    /**
Creates a new AudioManager and runs SDL_Mixer setup
*/
    AudioManager();
  
    ~AudioManager();


    /**
    Plays a single-fire Audioclip. Optional boolean to loop.
    */
    void Play(AudioClip* clip, bool loop = false);




    /**
Plays a music track on a constant loop until stopped.
*/
    void Play(MusicClip* clip);

};
