#include "PlayerInventory.h"
#include "ItemSystem/UsableItem.h"

PlayerInventory::PlayerInventory()
{
	m_equipmentSlots = {
		{Head, nullptr},
		{Shoulder, nullptr},
		{Chest, nullptr},
		{Legs, nullptr},
		{LeftHand, nullptr},
		{RightHand, nullptr},
		{Feet, nullptr}
	};
}

void PlayerInventory::UseItem(Item* item)
{
	if (ContainsItem(item))
	{
		UsableItem* usable = dynamic_cast<UsableItem*>(item);
		if(usable != nullptr)
			usable->Use();
	}
}

void PlayerInventory::EquipItem(Equippable* item)
{
	if (IsEquipmentSlotFree(item->GetSlot()))
	{
		m_equipmentSlots.find(item->GetSlot())->second = item;
	}
	else
	{
		if (GetRemainingSlots() > 0)
		{
			UnequipItem(item->GetSlot());
			m_equipmentSlots.find(item->GetSlot())->second = item;
		}
	}
}

void PlayerInventory::UnequipItem(SlotName item)
{
	if (GetRemainingSlots() > 0)
	{
		AddItem(m_equipmentSlots.find(item)->second);
		m_equipmentSlots.find(item)->second = nullptr;
	}
}

bool PlayerInventory::IsItemEquipped(Equippable* item)
{
	if (m_equipmentSlots.find(item->GetSlot())->second == item)
	{
		return true;
	}
	else
	{
		return false;
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
