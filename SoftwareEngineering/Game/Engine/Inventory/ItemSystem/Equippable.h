#pragma once
#include "UsableItem.h"
#include "EquipmentSlots.h"
class Equippable :
	public UsableItem
{
private:
	bool m_equipped = false;
	SlotName m_slot = Head;

public:
	SlotName GetSlot() { return m_slot; }
	void SetSlot(SlotName slot) { m_slot = slot; }

protected:
	void OnUsed() override;
};

