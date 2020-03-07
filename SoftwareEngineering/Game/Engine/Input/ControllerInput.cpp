#include "ControllerInput.h"
#include <stdio.h>
#include <iostream>

bool ControllerInput::Initialization()
{
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if (SDL_Init(SDL_INIT_JOYSTICK < 0))
    {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        success = false;
    }

    //Check for joysticks
    if (SDL_NumJoysticks() < 1)
    {
        printf("Warning: No joysticks connected!\n");
    }
    else
    {
        //Load joystick
        Controller = SDL_JoystickOpen(0);
        if (Controller == NULL)
        {
            printf("Warning: Unable to open game controller! SDL Error: %s\n", SDL_GetError());
        }
    }

    return success;
}


ControllerInput::ControllerInput()
{

}

ControllerInput::~ControllerInput()
{
}

void ControllerInput::ReceiveEvent(SDL_Event* event)
{
    if (event->type == SDL_JOYAXISMOTION)
    {
        if (event->jaxis.which == 0)
        {
            if (event->jaxis.axis == 0)
            {
                std::cout << event->jaxis.value << std::endl;
            }
        }
    }
}

void ControllerInput::Release()
{
}


