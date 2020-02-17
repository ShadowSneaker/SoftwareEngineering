#include "WorldActor.h"

SVector3 WorldActor::Velocity()
{
	return m_velocity;
}

void WorldActor::SetVelocity(SVector3 velocity)
{
	m_velocity = velocity;
}

void WorldActor::IncreaseVelocity(SVector3 velocity)
{
	m_velocity += velocity;
}

void WorldActor::MoveLeft(float magnitude)
{
	m_position.SetX(m_position.GetX() - magnitude);
}

void WorldActor::MoveRight(float magnitude)
{
	m_position.SetX(m_position.GetX() + magnitude);
}

void WorldActor::MoveUp(float magnitude)
{
	m_position.SetY(m_position.GetY() - magnitude);
}

void WorldActor::MoveDown(float magnitude)
{
	m_position.SetY(m_position.GetY() + magnitude);
}
