#pragma once
#include "Inventory.h"

class ShopInventory : public Inventory
{
public:
	void BuyItemFromVender(Item* item, Inventory* buyer);
	void SellToVender(Item* item, Inventory* seller);
};

