#pragma once
class Item
{
private:
	bool m_stackable;
	int m_stackSize;
	int m_value;
	int m_weight;

	//ItemList* m_owner;
public:
	void Destroy();
	void UpdateOwner(/*Pointer to new inventory*/);

	bool IsStackable()const { return m_stackable; }
	int Weight()const { return m_weight; }
	int Value()const { return m_value; }

	bool IncrementStackSize()const
	{
		if (m_stackable)
			m_stackSize++;
		else
			m_stackSize = 1;
	}
	bool DecrementStackSize()const
	{
		if (m_stackable)
			m_stackSize--;
		else
			m_stackSize = 1;
	}
	int GetStackSize()const { return m_stackSize; }
	
	virtual void OnUsed() = 0;
	virtual void OnAdded() = 0;
	virtual void OnRemoved() = 0;
};