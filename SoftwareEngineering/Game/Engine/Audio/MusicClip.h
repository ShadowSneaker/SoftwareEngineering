


/**
Lewis Cleminson
DAC627 Software Engineering for Games: Professional Practice
MusicClip.h

*/

#include <SDL.h>
#include <SDL_audio.h>
#include <SDL_mixer.h>

#pragma once

class MusicClip
{
private:

    Mix_Music* myClip;

public:

    /**
   Sets global volumn of all music. Expecting integer value between 0 and 10. 5 is default.
   */
    void setVolumn(int volumn);


    /**
    Loads and creates a music clip from file located at specified filename. e.g.("Assets/ExampleSound.Wav")
    */
    MusicClip(const char* filename);
    ~MusicClip();

    /**
    Returns this objects music clip.
    */
    Mix_Music* GetClip();

};
