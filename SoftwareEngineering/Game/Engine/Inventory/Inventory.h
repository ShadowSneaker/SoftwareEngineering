#pragma once
#include <vector>

class Item;

class Inventory
{
private:
	std::vector<Item*> m_items;
public:
	void AddItem(Item* item);
	void RemoveItem(Item* item);

protected:
	virtual void OnItemAdded(Item* item) = 0;
	virtual void OnItemRemoved(Item* item) = 0;
};