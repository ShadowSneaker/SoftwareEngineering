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
        //printf("Warning: No joysticks connected!\n");
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
        //Motion on controller 0
        if (event->jaxis.which == 0)
        {
            //X axis motion
            if (event->jaxis.axis == 0)
            {
                //Left of dead zone
                if (event->jaxis.value < -JOYSTICK_DEAD_ZONE)
                {
                    xDirection = -1;
                }
                //Right of dead zone
                else if (event->jaxis.value > JOYSTICK_DEAD_ZONE)
                {
                    xDirection = 1;
                }
                else
                {
                    xDirection = 0;
                }
                //Y axis motion
            }
            else if (event->jaxis.axis == 1)
            {
                //Below of dead zone
                if (event->jaxis.value < -JOYSTICK_DEAD_ZONE)
                {
                    yDirection = -1;
                }
                //Above of dead zone
                else if (event->jaxis.value > JOYSTICK_DEAD_ZONE)
                {
                    yDirection = 1;
                }
                else
                {
                    yDirection = 0;
                }
            }

        }
    }
}

void ControllerInput::MoveImage(CImage* Image)
{
    if (JoyStickAngle == -45)
        Image->Transform.Location.SetX(Image->Transform.Location.GetX() += 1);
    else if (JoyStickAngle == 180)
        Image->Transform.Location.SetX(Image->Transform.Location.GetX() -= 1);
    else if (JoyStickAngle == -90)
        Image->Transform.Location.SetY(Image->Transform.Location.GetY() -= 1);
    else if (JoyStickAngle == 90)
        Image->Transform.Location.SetY(Image->Transform.Location.GetY() += 1);
}

void ControllerInput::Release()
{
}

double ControllerInput::CalculateJSAngle(int xDirecton, int yDirection)
{
    JoyStickAngle = atan2((double)yDirection, (double)xDirecton) * (180.0 / M_PI);

    //Correct angle
    if (xDirection == 0 && yDirection == 0)
    {
        JoyStickAngle = 0;
        return JoyStickAngle;
    }

   
    return JoyStickAngle;
}


