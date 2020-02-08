#pragma once
#include <vector>

class Item;
class Entity;

class Inventory
{
private:

	std::vector<Item*>	m_items;
	Entity*				m_owner;

	int					m_maxSlots;

public:

	void	AddItem(Item* item);
	void	RemoveItem(Item* item);

	bool	ContainsItem(Item* item);
	bool	IsFull();

	int		GetRemainingSlots();
	int		GetTakenSlots();
	int		CountMoney();	// Need to create money item.

protected:

	std::vector<Item*>	GetItems();
	Entity*				GetOwner();
	int					GetMaxSlots();

	virtual void OnItemAdded(Item* item) = 0;
	virtual void OnItemRemoved(Item* item) = 0;

};