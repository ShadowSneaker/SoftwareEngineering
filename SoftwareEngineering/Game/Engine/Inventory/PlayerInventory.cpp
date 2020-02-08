#include "PlayerInventory.h"

void PlayerInventory::UseItem(Item* item)
{
	if (ContainsItem(item))
	{
		item->Use();
	}
}

bool PlayerInventory::IsEquipmentSlotFree(SlotName equipmentSlot)
{
	if (m_equipmentSlots.find(equipmentSlot)->second)
	{
		return false;
	}
	else
	{
		return true;
	}
}
