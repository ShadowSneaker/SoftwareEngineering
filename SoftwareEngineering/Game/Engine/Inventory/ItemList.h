#pragma once
#include <vector>

class Item;

class ItemList
{
private:
	std::vector<Item*> m_items;
public:
	void AddItem(Item* item);
	void RemoveItem(Item* item);

	virtual void OnItemAdded(Item* item) = 0;
	virtual void OnItemRemoved(Item* item) = 0;
};