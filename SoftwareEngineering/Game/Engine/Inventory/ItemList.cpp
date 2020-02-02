#include "ItemList.h"
#include "ItemSystem/Item.h"

ItemList::AddItem(Item* item)
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

ItemList::RemoveItem(Item* item)
{
	bool containsItem = std::find(m_items.begin(), m_items.end(), item) != m_items.end();
	if (!containsItem)return;

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