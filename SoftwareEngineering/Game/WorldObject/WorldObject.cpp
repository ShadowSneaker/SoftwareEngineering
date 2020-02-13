#include "WorldObject.h"

SVector3 WorldObject::Position()
{
	return m_position;
}

void WorldObject::SetPosition(SVector3 position)
{
	m_position = position;
}

void WorldObject::Move(SVector3 movement)
{
	m_position += movement;
}

SVector2 WorldObject::Scale()
{
	return m_scale;
}

void WorldObject::SetScale(SVector2 scale)
{
	m_scale = scale;
}

void WorldObject::ScaleBy(SVector2 scalar)
{
	//m_scale.X() *= scalar.X;
	//m_scale.Y() *= scalar.Y;

	//m_scale.Set(m_scale.X() * scalar.X(), m_scale.Y() * scalar.Y());
}

void WorldObject::ScaleBy(float scalar)
{
	m_scale *= scalar;
}

float WorldObject::Heading()
{
	return m_heading;
}

void WorldObject::SetHeading(float heading)
{
	m_heading = heading;
	validateHeading();
}

void WorldObject::Rotate(float rotation)
{
	m_heading += rotation;
	validateHeading();
}

bool WorldObject::IsActive()
{
	return m_isActive;
}

void WorldObject::SetIsActive(bool isActive)
{
	m_isActive = isActive;
}

void WorldObject::ToggleIsActive()
{
	m_isActive = !m_isActive;
}

void WorldObject::validateHeading()
{
	if (m_heading > 360.0f)
	{
		m_heading = m_heading - 360.0f;
	}
	else if (m_heading < 0.0f)
	{
		m_heading = m_heading + 360.0f;
	}
}
