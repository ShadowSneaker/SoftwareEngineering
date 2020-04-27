#pragma once
#include <string>

class Image;
class Inventory;

class Item
{
private:
	std::string m_id = " ";
	std::string m_name = " ";
	Image* m_icon = nullptr;
	bool m_isQuestItem = false;
	int m_stackSize = 1;
	bool m_stackable = false;
	int m_value = 0;
	int m_weight = 0;

	Inventory* m_owner = nullptr;
	

	
public:
	
	void Destroy();
	void UpdateOwner(Inventory* newOwner);
	Inventory* GetOwner() { return m_owner; }
	virtual Item* Clone() { return new Item(*this); }

	std::string GetID() { return m_id; }
	void SetID(std::string id) { m_id = id; }
	bool IsStackable()const { return m_stackable; }
	int GetWeight()const { return m_weight; }
	void SetWeight(int weight) { m_weight = weight; }
	int GetValue()const { return m_value; }
	void SetValue(int value) { m_value = value; }
	void SetIsStackable(bool stackable) { m_stackable = stackable; }
	void SetIsQuestItem(bool isQuestItem) { m_isQuestItem = isQuestItem; }

	std::string GetName() { return m_name; }
	void SetName(std::string name) { m_name = name; }

	//The setters for stacksize are the incrementing and decrementing functions
	void IncrementStackSize();
	void DecrementStackSize();
	int GetStackSize()const { return m_stackSize; }
	

	virtual void OnAdded();
	virtual void OnRemoved();
};
