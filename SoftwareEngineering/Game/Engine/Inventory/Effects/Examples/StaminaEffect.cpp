#include "StaminaEffect.h"

void StaminaEffect::StartEffect()
{
	Effect::StartEffect();
	//Player.stamina += StaminaAmount;
}

void StaminaEffect::EndEffect()
{
	Effect::EndEffect();
	//Player.stamina -= StaminaAmount;
}
