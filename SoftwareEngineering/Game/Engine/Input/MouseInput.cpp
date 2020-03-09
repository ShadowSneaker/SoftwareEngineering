#include "MouseInput.h"

//initialise mouse position and buttons
MouseInput::MouseInput()
{
	SDL_GetMouseState(&m_MousePos.x, &m_MousePos.y);
	for (int i = 0; i < sizeof(m_Mouse_Change); ++i)
		m_Mouse_Change[i] = false;
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
			m_Mouse_Change[Mouse_Button_Left] = true;
			break;

		case SDL_BUTTON_RIGHT:
			m_Mouse_Change[Mouse_Button_Right] = true;
			break;
		default:
			break;

		}
		return true;
	}
	//button false if released
	else if (pass_event->type == SDL_MOUSEBUTTONUP)
	{
		//unselect image
		if (ImageSelected) ImageSelected = false;

		//which button
		SDL_MouseButtonEvent Mouse_Button = pass_event->button;
		switch (Mouse_Button.button)
		{
		case SDL_BUTTON_LEFT:
			m_Mouse_Change[Mouse_Button_Left] = false;
			break;
		case SDL_BUTTON_RIGHT:
			m_Mouse_Change[Mouse_Button_Right] = false;
			break;
		default:
			break;
		}
		return true;
	}
	else if (pass_event->type == SDL_MOUSEWHEEL)
	{
		if (pass_event->wheel.y > 0)
		{
			MouseWheel_y -= WheelStrength;
			m_Mouse_Change[Mouse_Wheel_Up] = true; m_Mouse_Change[Mouse_Wheel_Down] = false;

		}
		else if (pass_event->wheel.y < 0)
		{
			MouseWheel_y += WheelStrength;
			m_Mouse_Change[Mouse_Wheel_Down] = true; m_Mouse_Change[Mouse_Wheel_Up] = false;

		}
	}
	//else
	//{
	//	m_Mouse_Change[Mouse_Wheel_Down] = false; m_Mouse_Change[Mouse_Wheel_Up] = false;
	//}
	//updates the mouse position
	SDL_GetMouseState(&m_MousePos.x, &m_MousePos.y);
	return false;
}

bool MouseInput::CheckMouse(Mouse_enum Mouse_Change)
{
	if (Mouse_Change == Mouse_Button_Left)
	{
		if (m_Mouse_Change[Mouse_Button_Left])
			return true;
	}

	else if (Mouse_Change == Mouse_Button_Right)
	{
		if (m_Mouse_Change[Mouse_Button_Right])
			return true;
	}

	else if (Mouse_Change == Mouse_Wheel_Down)
	{
		if (m_Mouse_Change[Mouse_Wheel_Down])
			return true;
	}

	else if (Mouse_Change == Mouse_Wheel_Up)
	{
		if (m_Mouse_Change[Mouse_Wheel_Up])
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
