#include <iostream>
#include "MoneyCountTest.h"
#include "Engine/Inventory/Inventory.h"
#include "Engine/Inventory/ItemSystem/MoneyItem.h"

void MoneyCountTest::Test(int moneyToAdd)
{
	Inventory inventory;
	MoneyItem temp;

	for (int i = 0; i < moneyToAdd; i++) 
	{
		inventory.AddItem(temp.Clone());
	}

	std::cout << inventory.CountMoney() << std::endl;
}
