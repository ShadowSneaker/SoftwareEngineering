#include "WorldObject.h"

int WorldObject::worldObjectIdIndex = 0;
std::vector<WorldObject*> WorldObject::worldObjects;

WorldObject::WorldObject()
	: m_heading{ 0.0f }, m_isActive{ true }, m_scale{ 1.0f, 1.0f }, m_position{ 0.0f, 0.0f, 0.0f }
{
	m_ID = worldObjectIdIndex;
	worldObjectIdIndex++;
}

WorldObject::WorldObject(SVector3 position, float heading, SVector2 scale, int worldObjectId, bool isActive)
{
	m_position = position;
	m_scale = scale;
	m_heading = heading;
	m_isActive = isActive;

	if (worldObjectId != -1)
	{
		m_ID = worldObjectId;
	}
	else
	{
		m_ID = worldObjectIdIndex;
		worldObjectIdIndex++;
	}
}

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
	m_scale.Set(m_scale.X() * scalar.X(), m_scale.Y() * scalar.Y());
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

int WorldObject::GetId()
{
	return m_ID;
}

WorldObject* WorldObject::GetWorldObjectById(int id)
{
	return worldObjects[id];
}

int WorldObject::NumberOfWorldObjects()
{
	return worldObjects.size() - 1;
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
