#pragma once
#include "../Effect.h"

class DamageBuffEffect : public Effect
{
public:
	int DamageBuffAmount = 0;

	void StartEffect() override;
	void EndEffect() override;
};

