#pragma once
#include "Inventory.h"

class ShopInventory : public Inventory
{
public:
	void BuyItemFromMe(Item* item, Inventory* buyer);
	void SellItemToMe(Item* item, Inventory* seller);
};

