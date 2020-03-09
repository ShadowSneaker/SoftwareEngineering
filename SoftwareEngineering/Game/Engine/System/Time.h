#pragma once
#include <CopiriteMath/MathGlobals.h>



class TTime
{
public:
	/// Static Properties

	static float DeltaTime;

	static float TimeScale;

	static float Time;


private:
	/// Properties

	uint64 Previous{ 0 };
	uint64 Current{ 0 };



public:
	/// Constructors

	TTime();



	/// Functions

	void Update();
};