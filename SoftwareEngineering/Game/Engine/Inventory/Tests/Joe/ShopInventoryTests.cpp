#include <iostream>
#include "ShopInventoryTests.h"
#include "../../ShopInventory.h"
#include "../../ItemSystem/Item.h"
#include "../../ItemSystem/MoneyItem.h"

void ShopInventoryTests::TestBuyFrom()
{
	ShopInventory from;
	Item tempItem;
	tempItem.SetValue(3);

	Item* item = tempItem.Clone();
	from.AddItem(item);
	
	Inventory to;
	int money = 2;
	MoneyItem moneyItem;
	for (int i = 0; i < money; i++)
	{
		to.AddItem(moneyItem.Clone());
	}

	from.BuyItemFromMe(item, &to);
	std::cout << "Buying item..." << std::endl;
	std::cout << "Item added: " << to.ContainsItem(item) << std::endl;
}

void ShopInventoryTests::TestSellTo()
{
	ShopInventory from;
	Item tempItem;
	tempItem.SetValue(3);

	Item* item = tempItem.Clone();
	int money = 2;
	MoneyItem moneyItem;
	for (int i = 0; i < money; i++)
	{
		from.AddItem(moneyItem.Clone());
	}

	Inventory to;
	to.AddItem(item);

	from.SellItemToMe(item, &to);
	std::cout << "Buying item..." << std::endl;
	std::cout << "Item added: " << from.ContainsItem(item) << std::endl;
}
