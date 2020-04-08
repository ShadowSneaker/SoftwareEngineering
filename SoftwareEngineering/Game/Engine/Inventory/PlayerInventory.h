#pragma once

#include <map>
#include "Inventory.h"
#include "ItemSystem/Item.h"
#include "ItemSystem/EquipmentSlots.h"
#include "ItemSystem/Equippable.h"

class PlayerInventory :
	public Inventory
{
private:

	std::map<SlotName, Item*>	m_equipmentSlots;

public:

	PlayerInventory();

	void	UseItem(Item* item);
	void	EquipItem(Equippable* item);		// Need equippable item implementation
	void	UnequipItem(SlotName item);	// ^^

	bool	IsItemEquipped(Item* item);
	bool	IsEquipmentSlotFree(SlotName equipmentSlot);

};

