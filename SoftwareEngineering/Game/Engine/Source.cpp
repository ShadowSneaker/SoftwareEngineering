#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"
#include "Graphics/Images/Animation.h"
#include "System/Time.h"
#include "Level/Level.h"
#include "Inventory/Inventory.h"
#include "Inventory/ItemSystem/Item.h"


int main(int argc, char** argv)
{
	// Temporary code, this should be changed!

	TTime* Time{ new TTime{} };

	CRenderer* Renderer{ new CRenderer() };
	Renderer->SetBackgroundColour(SColour::Black());
	

	Renderer->SetMainCamera(TheCamera);

	CAnimation* Image{ new CAnimation() };
	Image->SetImage("Content/Images/Anim.png");

	//CImage* TheImage{ new CImage() };
	//TheImage->SetImage("Content/Images/HappyBoi.png");
	//TheImage->Transform.Location = 300.0f;


	TheCamera->SetCameraPosition(300.0f,300.0f);

	Image->SetCellCount(1, 4);
	Image->Transform.Location = 300.0f;
	//Image->ReverseFromEnd();
	//Image->Stop();
	Image->Transform.Scale = 1.0f;
	Image->Pivot = Image->GetCellCenter();
	

	SDL_Event* Event{ new SDL_Event{} };

	Inventory* inventory = new Inventory();
	auto item = new Item();
	int i = 1;
	item->SetName("Item " + std::to_string(i));

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
		
		inventory->Draw(Renderer);

		Renderer->DrawAllImages();

		if(Event->type == SDL_KEYDOWN)
		{
			item->SetName("Item " + std::to_string(i));
			inventory->AddItem(item->Clone());
			i++;
		}
		
		SDL_PollEvent(Event);
	}

	return 1;
}