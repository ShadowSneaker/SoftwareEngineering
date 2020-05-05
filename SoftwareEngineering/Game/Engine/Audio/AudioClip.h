

/**
Lewis Cleminson
DAC627 Software Engineering for Games: Professional Practice
AudioClip.h

*/


#include <SDL.h>
#include <SDL_audio.h>
#include <SDL_mixer.h>

#pragma once




class AudioClip
{
private:
	

    Mix_Chunk* myClip;

public:

	
	/**
Sets volumn of this audio clip. Expecting integer value between 0 and 10. 5 is default.
*/
	void setVolumn(int volumn);

	/**
Loads and creates an audioclip from file located at specified filename. e.g.("Assets/ExampleSound.Wav")
*/
	AudioClip(const char* filename);
	~AudioClip();


	/**
returns this objects audioclip.
*/
    Mix_Chunk* GetClip();

};


