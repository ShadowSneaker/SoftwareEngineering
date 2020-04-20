#pragma once
#include <vector>

class Item;
class InventoryUI;
class CRenderer;
class WorldObject;

class Inventory
{
private:

	std::vector<Item*>	m_items;
	WorldObject*		m_owner;

	int					m_maxSlots;
	InventoryUI*		m_inventoryUI;

public:

	~Inventory();
	
	void	AddItem(Item* item);
	void	RemoveItem(Item* item);

	bool	ContainsItem(Item* item);
	bool	IsFull();

	int		GetRemainingSlots();
	int		GetTakenSlots();
	int		CountMoney();	// Need to create money item.

	void	Draw(CRenderer* renderer);

protected:

	std::vector<Item*>	GetItems();
	WorldObject*		GetOwner();
	int					GetMaxSlots();

	void virtual UpdateUIElements();

	virtual void OnItemAdded(Item* item) {};
	virtual void OnItemRemoved(Item* item) {};

};