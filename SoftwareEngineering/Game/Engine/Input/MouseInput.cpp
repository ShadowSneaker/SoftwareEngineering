#include "MouseInput.h"

//initialise mouse position and buttons
MouseInput::MouseInput()
{
	SDL_GetMouseState(&m_MousePos.x, &m_MousePos.y);
	for (int i = 0; i < sizeof(m_Mouse_Buttons_Pressed); ++i)
		m_Mouse_Buttons_Pressed[i] = false;
}

//Updates the mouse position and buttons							   
bool MouseInput::UpdateMouse(SDL_Event* pass_event)
{
	//Button true if pressed
	if (pass_event->type == SDL_MOUSEBUTTONDOWN)
	{
		//which button
		SDL_MouseButtonEvent Mouse_Button = pass_event->button;
		switch (Mouse_Button.button)
		{
		case SDL_BUTTON_LEFT:
			m_Mouse_Buttons_Pressed[Left] = true;
			break;

		case SDL_BUTTON_RIGHT:
			m_Mouse_Buttons_Pressed[Right] = true;
			break;
		default:
			break;

		}
		return true;
	}
	//button false if released
	else if (pass_event->type == SDL_MOUSEBUTTONUP)
	{
		//which button
		SDL_MouseButtonEvent Mouse_Button = pass_event->button;
		switch (Mouse_Button.button)
		{
		case SDL_BUTTON_LEFT:
			m_Mouse_Buttons_Pressed[Left] = false;
			if (ImageSelected) ImageSelected = false;
			break;

		case SDL_BUTTON_RIGHT:
			m_Mouse_Buttons_Pressed[Right] = false;
			break;
		default:
			break;
		}
		return true;
	}
	//updates the mouse position
	SDL_GetMouseState(&m_MousePos.x, &m_MousePos.y);
}

bool MouseInput::CheckButton(Clicks button)
{
	if (button == Left)
		if (m_Mouse_Buttons_Pressed[Left])
		{
			return true;
		}
	if (button == Right)
		if (m_Mouse_Buttons_Pressed[Right])
		{
			return true;
		}
	return false;
}

bool MouseInput::OnImage(CImage* Image)
{
	if ((getMousePos().x >= (Image->Transform.Location.GetX() - (0.5 * Image->GetImageSize().GetX()))
		&& (getMousePos().x <= (Image->Transform.Location.GetX() + (0.5 * Image->GetImageSize().GetX())))
		&& (getMousePos().y >= (Image->Transform.Location.GetY() - (0.5 * Image->GetImageSize().GetY()))))
		&& (getMousePos().y <= (Image->Transform.Location.GetY() + (0.5 * Image->GetImageSize().GetY()))))
		return true;
	else
		return false;
}

void MouseInput::MoveImage(CImage* Image)
{
	if (OnImage(Image) || ImageSelected)
	{
		Image->Transform.Location.SetX(m_MousePos.x);
		Image->Transform.Location.SetY(m_MousePos.y);
		ImageSelected = true;
	}

}

SDL_Point MouseInput::getMousePos()
{
	return {m_MousePos};
}