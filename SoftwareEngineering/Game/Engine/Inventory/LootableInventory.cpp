#include "LootableInventory.h"
#include "ItemSystem/Item.h"

void LootableInventory::Loot(int numDropped)
{
	std::vector<Item*> tempItems = GetItems();

	for (int i = 0; i < tempItems.size(); i++)
	{
		RemoveItem(tempItems[i]);
	}
}
