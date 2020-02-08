#pragma once
#include "UsableItem.h"
class Consumable :
	public UsableItem
{
protected:
	void OnUsed() override;
};

