#pragma once
#include "../Inventory.h"
#include <string>
class Image;

class Item
{
private:
	std::string m_name = " ";
	Image* m_icon = nullptr;
	bool m_isQuestItem = false;
	bool m_stackable = false;
	int m_stackSize = 1;
	int m_value = 0;
	int m_weight = 0;

	Inventory* m_owner = nullptr;
public:
	void Use();
	void Destroy();
	void UpdateOwner(Inventory* newOwner);

	bool IsStackable()const { return m_stackable; }
	int GetWeight()const { return m_weight; }
	void SetWeight(int weight) { m_weight = weight; }
	int GetValue()const { return m_value; }
	void SetValue(int value) { m_value = value; }

	//The setters for stacksize are the incrementing and decrementing functions
	void IncrementStackSize();
	void DecrementStackSize();
	int GetStackSize()const { return m_stackSize; }
	


	virtual void OnUsed() = 0;
	virtual void OnAdded() = 0;
	virtual void OnRemoved() = 0;
};
