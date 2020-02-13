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
