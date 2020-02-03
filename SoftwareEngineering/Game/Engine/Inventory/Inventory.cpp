#include "Inventory.h"
#include "ItemSystem/Item.h"
#include <algorithm>

void Inventory::AddItem(Item* item)
{
	bool containsItem = std::find(m_items.begin(), m_items.end(), item) != m_items.end();

	if (containsItem && item->IsStackable())
	{
		item->IncrementStackSize();
	}
	else
	{
		m_items.push_back(item);
		item->IncrementStackSize();
	}

	item->OnAdded();
	OnItemAdded(item);
}

void Inventory::RemoveItem(Item* item)
{
	bool containsItem = std::find(m_items.begin(), m_items.end(), item) != m_items.end();

	//vector does not contain item, stop here...
	if (!containsItem) return;

	if (item->IsStackable())
	{
		if (item->GetStackSize() <= 1) 
		{
			m_items.erase(std::remove(m_items.begin(), m_items.end(), item), m_items.end());
		}
		else
		{
			item->DecrementStackSize();
		}
	}
	else
	{
		m_items.erase(std::remove(m_items.begin(), m_items.end(), item), m_items.end());
	}

	item->OnRemoved();
	OnItemRemoved(item);
}