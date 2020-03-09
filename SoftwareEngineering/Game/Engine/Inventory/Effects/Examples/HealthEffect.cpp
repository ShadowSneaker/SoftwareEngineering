#include "HealthEffect.h"

void HealthEffect::StartEffect()
{
	Effect::StartEffect();
	//Player.health += StaminaAmount;
}

void HealthEffect::EndEffect()
{
	Effect::EndEffect();
	//Player.health -= StaminaAmount;
}