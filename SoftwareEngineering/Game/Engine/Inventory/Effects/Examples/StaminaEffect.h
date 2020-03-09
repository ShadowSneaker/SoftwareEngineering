#pragma once
#include "../Effect.h"

class StaminaEffect : public Effect
{
public:
	int StaminaAmount = 0;
	
	void StartEffect() override;
	void EndEffect() override;
};

