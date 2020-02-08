#include "DamageBuffEffect.h"

void DamageBuffEffect::StartEffect()
{
	Effect::StartEffect();
	//Player.damage += StaminaAmount;
}

void DamageBuffEffect::EndEffect()
{
	Effect::EndEffect();
	//Player.damage -= StaminaAmount;
}