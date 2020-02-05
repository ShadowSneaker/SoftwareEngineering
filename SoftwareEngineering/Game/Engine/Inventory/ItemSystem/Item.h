#pragma once
#include "../Inventory.h"

class Item
{
private:
	bool m_stackable = false;
	int m_stackSize = 1;
	int m_value = 0;
	int m_weight = 0;

	Inventory* m_owner = nullptr;
public:
	void Destroy();
	void UpdateOwner(Inventory* newOwner);

	bool IsStackable()const { return m_stackable; }
	int Weight()const { return m_weight; }
	int Value()const { return m_value; }

	void IncrementStackSize();
	void DecrementStackSize();
	int GetStackSize()const { return m_stackSize; }

	virtual void OnUsed() = 0;
	virtual void OnAdded() = 0;
	virtual void OnRemoved() = 0;
};
