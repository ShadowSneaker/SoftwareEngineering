#pragma once

#include <CopiriteMath/Datatypes/Vector.h>

class WorldObject
{
private:

	void		validateHeading(); // Keeps heading within 0 - 360 degrees

protected:

	SVector3	m_position;
	SVector2	m_scale;
	float		m_heading;

	// ToBeDefined	m_worldObjectID;

	bool		m_isActive;

public:

	SVector3	Position();
	void		SetPosition(SVector3 position);
	void		Move(SVector3 movement);

	SVector2	Scale();
	void		SetScale(SVector2 scale);
	void		ScaleBy(SVector2 scalar);
	void		ScaleBy(float scalar);

	float		Heading();
	void		SetHeading(float heading);
	void		Rotate(float rotation);

	// ToBeDefined ID();

	bool		IsActive();
	void		SetIsActive(bool isActive);
	void		ToggleIsActive();

};

