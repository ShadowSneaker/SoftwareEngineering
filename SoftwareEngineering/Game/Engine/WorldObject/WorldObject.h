#pragma once

#include <CopiriteMath/Datatypes/Vector.h>
#include <string>
#include <vector>

class WorldObject
{
private:

	static std::vector<WorldObject*>	worldObjects;
	static int							worldObjectIdIndex;

	void	validateHeading(); // Keeps heading within 0 - 360 degrees

protected:

	SVector3	m_position;
	SVector2	m_scale;
	float		m_heading = 0.0f;

	int			m_ID;

	bool		m_isActive;

public:

	WorldObject();
	WorldObject(SVector3 position = { 0.0f, 0.0f, 0.0f }, float heading = 0.0f, SVector2 scale = { 1.0f, 1.0f }, int worldObjectId = -1, bool isActive = true);

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

	bool		IsActive();
	void		SetIsActive(bool isActive);
	void		ToggleIsActive();

	int			GetId();

	static WorldObject*	GetWorldObjectById(int id);
	static int NumberOfWorldObjects();

};