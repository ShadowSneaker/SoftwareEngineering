#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"

#include "Graphics/Images/Animation.h"
#include "System/Time.h"
#include "System/Camera.h"

#include "Input/InputManager.h"
#include <SDL_thread.h>
#include <SDL.h>
//#include "Source.h"
#include <stdio.h>
#include <string>

SDL_Event* Event{ new SDL_Event{} };
InputManager* inputManager = new InputManager();
//CImage* Image{ new CImage() };
//CImage* Image2{ new CImage() };

int ControllerThread(void* threadData)
{

	inputManager->GetController()->ReceiveEvent(Event);
	inputManager->GetController()->CalculateJSAngle(inputManager->GetController()->xDirection, inputManager->GetController()->yDirection);
	//inputManager->GetController()->MoveImage(Image);

	return 0;
}


#include "UI/SampleUI.h"
#include "../Label.h"

int main(int argc, char** argv)
{
	// Temporary code, this should be changed!

	TTime* Time{ new TTime{} };

	CRenderer* Renderer{ new CRenderer() };

	Renderer->SetBackgroundColour(SColour::Black());
	

	CCamera* TheCamera{ new CCamera() };

	Renderer->SetMainCamera(TheCamera);

	SampleUI* ui = new SampleUI(Renderer);

	TTF_Font* font = TTF_OpenFont("Content/Fonts/Roboto-Regular.ttf", 12);
	if (font == NULL) {
		std::cout << "Failed to load font" << std::endl;
	}

	CAnimation* Image{ new CAnimation() };
	Image->SetImage("Content/Images/Anim.png");

	//CImage* TheImage{ new CImage() };
	//TheImage->SetImage("Content/Images/HappyBoi.png");
	//TheImage->Transform.Location = 300.0f;


	TheCamera->SetCameraPosition(300.0f,300.0f);

	Renderer->SetBackgroundColour(SColour::DarkGray());
	Renderer->SetImage(Image, "Content/Images/HappyBoi.png", false);
	//Renderer->SetImage(Image2, "Content/Images/HappyBoi2.png", false);
	Renderer->AddImage(Image);
	//Renderer->AddImage(Image2);


	Image->SetCellCount(1, 4);
	Image->Transform.Location = 300.0f;
	//Image->ReverseFromEnd();
	//Image->Stop();
	Image->Transform.Scale = 1.0f;
	Image->Pivot = Image->GetCellCenter();
	

	SDL_Event* Event{ new SDL_Event{} };

	float Timer = 0.0f;
	bool Bop = false;


	//float MovedLocation = 340.0f;
	//TheImage->Transform.Location = MovedLocation;

	

	/*Image2->Transform.Location = 300.0f;
	Image2->SetColour(255, 255, 0, 255);*/
	//-----------------------------------MOUSE STUFF--------------------------//
	//how much the mouse wheel affects stuff
	inputManager->GetMouse()->SetWheelStrength(100);
	float cursor_Sensitivity = 1;
	//makes the image the cursor
	inputManager->GetMouse()->SetCursorImage(Image);//COMMENT IF YOU WANT TO USE MOUSE !ON_IMAGE
	SDL_ShowCursor(0);//switches cursor off


	while (Event->type != SDL_QUIT)
	{
		Timer += TTime::DeltaTime;
		if (Timer > 2.0f && !Bop)
		{

			Timer = 0.0f;
			Bop = true;
			//if (Image->IsPlaying()) Image->ReverseFromEnd();
			//Image->ReverseFromEnd();

			int data = 10;

			SDL_Thread* threadID = SDL_CreateThread(ControllerThread, "Controller Thread", (void*)data);

			inputManager->Update(Event);


			if ((inputManager->GetMouse()->CheckMouse(Mouse_Button_Left) && (inputManager->GetMouse()->OnImage(Image))) || inputManager->GetMouse()->ImageSelected)
			{
				Image->SetColour(255, 0, 0, 255);
				cursor_Sensitivity*=1.05;
				//inputManager->GetMouse()->MoveImage(Image);
			}
			else if (inputManager->GetMouse()->CheckMouse(Mouse_Button_Left))
			{
				
			}
			else if (inputManager->GetMouse()->CheckMouse(Mouse_Button_Right) && inputManager->GetMouse()->OnImage(Image))
			{
				cursor_Sensitivity/=1.05;
				SDL_ShowCursor(1); //switches cursor on
			}
			else if (inputManager->GetMouse()->CheckMouse(Mouse_Button_Right))
			{
				//Switches cursor on
				//SDL_ShowCursor(1);
			}
			//move something up and down using mouse wheel
			else if (inputManager->GetMouse()->CheckMouse(Mouse_Wheel_Down) || inputManager->GetMouse()->CheckMouse(Mouse_Wheel_Up))
			{
				//moves image with wheel
	/*			Image->Transform.Location.SetY(inputManager->GetMouse()->GetMouseWheel());*/
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



		
		//Image->AnimationTestFunction();
		//Time->Update();
		Renderer->Clear();
		ui->drawAllElements();
		Renderer->DrawAllImages();
		ui->updateAllElements();
		//TheImage->SetColour(255, 0, 0); // sets it to red
		//TheImage->TestImageColour(255, 0, 0); // tests if its red
		TheCamera->CameraTesterFunction(Image);

		//TheImage->TestImageLocation(MovedLocation, MovedLocation);
		//Renderer->RenderImagePixelTest(TheImage, 300, 300);

		SDL_PollEvent(Event);
	}

	return 1;
}


