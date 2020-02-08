#pragma once

#include "Inventory.h"

class LootableInventory : public Inventory
{
protected:

	virtual void OnLoot() = 0;

public:

	void Loot(int numDropped);

};