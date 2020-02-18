#include "Graphics/Renderer/SDLSetup.h"
#include "Graphics/Renderer/Renderer.h"
#include "Systems/Time.h"


int main(int argc, char** argv)
{
	// Temporary code, this should be changed!
	TTime* Time{ new TTime{} };

	CRenderer* Renderer{ new CRenderer() };
	Renderer->SetBackgroundColour(SColour::Pink());
	
	CImage* Image{ new CImage() };
	Renderer->SetImage(Image, "Content/Images/HappyBoi.png", false);
	Renderer->AddImage(Image);

	Image->Transform.Location = 300.0f;
	//Image->SetColour(SColour::Cyan());

	CImage* ImageTwo{ new CImage() };
	Renderer->SetImage(ImageTwo, "Content/Images/Robo.png", false);
	Renderer->AddImage(ImageTwo);

	ImageTwo->Transform.Location = 300.0f;


	ImageTwo->SetColour(255, 0, 0, 255);


	ImageTwo->Transform.Scale = 5.0f;
	ImageTwo->Pivot = ImageTwo->GetImageCenter();
	ImageTwo->Pivot.Print();
	SDL_Event* Event{ new SDL_Event{} };


	while (Event->type != SDL_QUIT)
	{
		Time->Update();

		Renderer->DrawAllImages();
		SDL_PollEvent(Event);
		ImageTwo->Transform.Rotation += 1.0f;
	}

	return 1;
}