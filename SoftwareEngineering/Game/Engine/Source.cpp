#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"
#include "Graphics/Images/Animation.h"
#include "System/Time.h"
#include "System/Camera.h"



int main(int argc, char** argv)
{
	// Temporary code, this should be changed!

	TTime* Time{ new TTime{} };

	CRenderer* Renderer{ new CRenderer() };
	Renderer->SetBackgroundColour(SColour::Black());
	
	CCamera* TheCamera{ new CCamera() };

	Renderer->SetMainCamera(TheCamera);

	CAnimation* Image{ new CAnimation() };
	Image->SetImage("Content/Images/Anim.png");

	//CImage* TheImage{ new CImage() };
	//TheImage->SetImage("Content/Images/HappyBoi.png");
	//TheImage->Transform.Location = 300.0f;


	TheCamera->SetCameraPosition(300.0f,300.0f);

	Image->SetCellCount(1, 5);
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

	

	while (Event->type != SDL_QUIT)
	{
		Timer += TTime::DeltaTime;
		if (Timer > 2.0f && !Bop)
		{
			Timer = 0.0f;
			Bop = true;
			//if (Image->IsPlaying()) Image->ReverseFromEnd();
			//Image->ReverseFromEnd();

			
		}
		
		//Image->AnimationTestFunction();
		Time->Update();
		Renderer->DrawAllImages();
		//TheImage->SetColour(255, 0, 0); // sets it to red
		//TheImage->TestImageColour(255, 0, 0); // tests if its red


		//TheImage->TestImageLocation(MovedLocation, MovedLocation);
		//Renderer->RenderImagePixelTest(TheImage, 300, 300);
		SDL_PollEvent(Event);
	}

	return 1;
}


