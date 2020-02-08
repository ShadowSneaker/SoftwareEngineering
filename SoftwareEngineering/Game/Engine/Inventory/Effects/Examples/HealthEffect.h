#pragma once
#include "../Effect.h"

class HealthEffect : public Effect
{
public:
	int HealthAmount = 0;

	void StartEffect() override;
	void EndEffect() override;
};

