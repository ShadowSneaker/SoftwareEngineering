#include "ShopInventory.h"
#include "ItemSystem/Item.h"

void ShopInventory::BuyItemFromVender(Item* item, Inventory* buyer)
{
	//TODO: buying and stuff
	if (buyer->CountMoney() >= item->GetValue()) 
	{
		//Take away money from buyer inventory
		RemoveItem(item);
		buyer->AddItem(item);
	}
}

void ShopInventory::SellToVender(Item* item, Inventory* seller)
{
	//TODO: selling and stuff
	if (CountMoney() >= item->GetValue())
	{
		//Take away money from my inventory
		seller->RemoveItem(item);
		AddItem(item);
	}
}
