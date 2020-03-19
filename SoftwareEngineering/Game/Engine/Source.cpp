#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"
#include "Input/InputManager.h"
#include <SDL_thread.h>
#include <SDL.h>
#include "Source.h"
#include <stdio.h>
#include <string>

SDL_Event* Event{ new SDL_Event{} };
InputManager* inputManager = new InputManager();
CImage* Image{ new CImage() };

int ControllerThread(void* threadData)
{

	inputManager->GetController()->ReceiveEvent(Event);
	inputManager->GetController()->CalculateJSAngle(inputManager->GetController()->xDirection, inputManager->GetController()->yDirection);

	if (inputManager->GetController()->JoyStickAngle == -45)
		Image->Transform.Location.SetX(Image->Transform.Location.GetX() += 1);
	else if (inputManager->GetController()->JoyStickAngle == 180)
		Image->Transform.Location.SetX(Image->Transform.Location.GetX() -= 1);
	else if (inputManager->GetController()->JoyStickAngle == -90)
		Image->Transform.Location.SetY(Image->Transform.Location.GetY() -= 1);
	else if (inputManager->GetController()->JoyStickAngle == -180)
		Image->Transform.Location.SetY(Image->Transform.Location.GetY() += 1);

	return 0;
}



int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	CRenderer* Renderer{ new CRenderer() };
	
	Renderer->SetBackgroundColour(SColour::DarkGray());
	Renderer->SetImage(Image, "Content/Images/HappyBoi.png", false);
	Renderer->AddImage(Image);

	Image->Transform.Location = 300.0f;
	Image->SetColour(0, 255, 0, 255);

	//-----------------------------------MOUSE STUFF--------------------------//
	//how much the mouse wheel affects stuff
	inputManager->GetMouse()->SetWheelStrength(100);
	float cursor_Sensitivity = 1;
	//makes the image the cursor
	inputManager->GetMouse()->SetCursorImage(Image);//UNCOMMENT IF YOU WANT TO USE MOUSE !ON_IMAGE
	SDL_ShowCursor(0);//switches cursor off

	while (Event->type != SDL_QUIT)
	{
		while (SDL_PollEvent(Event))
		{
			int data = 10;

			SDL_Thread* threadID = SDL_CreateThread(ControllerThread, "Controller Thread", (void*)data);

			inputManager->Update(Event);

			if ((inputManager->GetMouse()->CheckMouse(Mouse_Button_Left) && (inputManager->GetMouse()->OnImage(Image))) || inputManager->GetMouse()->ImageSelected)
			{
				Image->SetColour(255, 0, 0, 255);
				cursor_Sensitivity*=1.05;
				inputManager->GetMouse()->MoveImage(Image);
			}
			else if (inputManager->GetMouse()->CheckMouse(Mouse_Button_Left))
			{
				
			}
			else if (inputManager->GetMouse()->CheckMouse(Mouse_Button_Right) && inputManager->GetMouse()->OnImage(Image))
			{
				cursor_Sensitivity*=0.9;
				SDL_ShowCursor(1); //switches cursor on
			}
			else if (inputManager->GetMouse()->CheckMouse(Mouse_Button_Right))
			{
				SDL_ShowCursor(1);
			}
			//move something up and down using mouse wheel
			else if (inputManager->GetMouse()->CheckMouse(Mouse_Wheel_Down) || inputManager->GetMouse()->CheckMouse(Mouse_Wheel_Up))
			{
			}

			if (inputManager->GetKeyboard()->IsKeyPressed(KEY_CONFIRM))
			{
				Image->SetColour(0, 0, 255, 255);
				//std::cout << "Test" << std::endl;
			}

			inputManager->GetMouse()->SetMouseWheel(Image->Transform.Location.GetY());
			inputManager->GetMouse()->SetSensitivity(cursor_Sensitivity);
			SDL_WaitThread(threadID, NULL);
			Renderer->DrawAllImages();
		}

	}



	delete inputManager;
	inputManager = nullptr;

	return 1;
}
