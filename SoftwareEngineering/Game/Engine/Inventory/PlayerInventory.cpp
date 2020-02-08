#include "PlayerInventory.h"
#include "ItemSystem/UsableItem.h"

void PlayerInventory::UseItem(Item* item)
{
	if (ContainsItem(item))
	{
		UsableItem* usable = dynamic_cast<UsableItem*>(item);
		if(usable != nullptr)
			usable->Use();
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
