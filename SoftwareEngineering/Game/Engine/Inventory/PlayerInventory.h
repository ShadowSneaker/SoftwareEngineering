#pragma once

#include <map>
#include "Inventory.h"
#include "ItemSystem/Item.h"
#include "ItemSystem/EquipmentSlots.h"

class PlayerInventory :
	public Inventory
{
private:

	std::map<SlotName, Item*>	m_equipmentSlots;

public:

	void	UseItem(Item* item);
	void	EquipItem(Item* item);		// Need equippable item implementation
	void	UnequipItem(Item* item);	// ^^

	bool	IsItemEquipped(Item* item);
	bool	IsEquipmentSlotFree(SlotName equipmentSlot);

};

