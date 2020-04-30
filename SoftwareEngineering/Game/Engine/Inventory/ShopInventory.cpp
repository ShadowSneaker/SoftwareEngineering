#include "ShopInventory.h"
#include "ItemSystem/Item.h"

void ShopInventory::BuyItemFromMe(Item* item, Inventory* buyer)
{
	//TODO: buying and stuff
	if (buyer->CountMoney() >= item->GetValue()) 
	{
		//Take away money from buyer inventory
		RemoveItem(item);
		buyer->AddItem(item);
	}
}

void ShopInventory::SellItemToMe(Item* item, Inventory* seller)
{
	//TODO: selling and stuff
	if (CountMoney() >= item->GetValue())
	{
		//Take away money from my inventory
		seller->RemoveItem(item);
		AddItem(item);
	}
}
