#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"
#include "Input/MouseInput.h"
#include "Input/KeyboardInput.h"
#include "Input/ControllerInput.h"
#include <SDL_thread.h>
#include <SDL.h>
#include "Source.h"
#include <stdio.h>
#include <string>

SDL_Event* Event{ new SDL_Event{} };
ControllerInput* Controller = new ControllerInput();
CImage* Image{ new CImage() };

int ControllerThread(void* threadData)
{

	Controller->ReceiveEvent(Event);
	Controller->CalculateJSAngle(Controller->xDirection, Controller->yDirection);

	if (Controller->JoyStickAngle == -45)
		Image->Transform.Location.SetX(Image->Transform.Location.GetX() += 1);
	else if (Controller->JoyStickAngle == 180)
		Image->Transform.Location.SetX(Image->Transform.Location.GetX() -= 1);
	else if (Controller->JoyStickAngle == -90)
		Image->Transform.Location.SetY(Image->Transform.Location.GetY() -= 1);
	else if (Controller->JoyStickAngle == -180)
		Image->Transform.Location.SetY(Image->Transform.Location.GetY() += 1);

	return 0;
}



int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	CRenderer* Renderer{ new CRenderer() };

	MouseInput* mouse = new MouseInput();
	KeyboardInput* Keyboard = new KeyboardInput();

	Controller->Initialization();

	Renderer->SetBackgroundColour(SColour::DarkGray());
	

	Renderer->SetImage(Image, "Content/Images/HappyBoi.png", false);
	Renderer->AddImage(Image);

	Image->Transform.Location = 300.0f;
	Image->SetColour(0,255,0,255);





	while (Event->type != SDL_QUIT)
	{

		SDL_PollEvent(Event);

		int data = 10;
		//int threadFunction(void* data);
		SDL_Thread* threadID = SDL_CreateThread(ControllerThread,"Controller Thread", (void*)data);

		//mouse stuff
		//if(mouse->UpdateMouse(Event));
		//{
		//	if ((mouse->CheckButton(Left) && (mouse->OnImage(Image))) || mouse->ImageSelected)
		//	{
		//		Image->SetColour(255, 0, 0, 255);
		//		mouse->MoveImage(Image);
		//	}
		//	else if (mouse->CheckButton(Left))
		//		Image->SetColour(0, 255, 0, 255);

		//	if (mouse->CheckButton(Right) && mouse->OnImage(Image))
		//		Renderer->SetBackgroundColour(SColour::Blue());
		//	else if (mouse->CheckButton(Right))
		//		Renderer->SetBackgroundColour(SColour::Black());
		//}

		Renderer->DrawAllImages();
		SDL_WaitThread(threadID, NULL);
	}



	delete mouse;
	mouse = nullptr;

	delete Keyboard;
	Keyboard = nullptr;

	delete Controller;
	Controller = nullptr;

	return 1;
}
