#pragma once
#include <CopiriteMath/MathGlobals.h>



class TTime
{
public:
	/// Static Properties

	// The time between the last frame and the currect frame (in ms).
	static float DeltaTime;

	// The scalar multiplied onto delta time.
	static float TimeScale;



private:
	/// Properties

	// The performance counter of the last frame.
	uint64 LastFrame{ 0 };

	// The performance counter of the current frame.
	uint64 CurrentFrame{ 0 };



public:
	/// Constructors

	// Constructor, Default.
	TTime();



	/// Functions

	// Updates the value of delta time.
	void Update();




};