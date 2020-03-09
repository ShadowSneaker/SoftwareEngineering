#pragma once
#include "WorldObject.h"

class WorldActor : public WorldObject
{
private:

	SVector3	m_velocity;

public:

	SVector3	Velocity();
	void		SetVelocity(SVector3 velocity);
	void		IncreaseVelocity(SVector3 velocity);

	void		MoveLeft(float magnitude);		// Isometric movement
	void		MoveRight(float magnitude);
	void		MoveUp(float magnitude);
	void		MoveDown(float magnitude);

};