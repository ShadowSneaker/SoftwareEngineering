#include <algorithm>
#include "Inventory.h"
#include "ItemSystem/Item.h"
#include "ItemSystem/MoneyItem.h"
#include "..//WorldObject/WorldObject.h"
#include "InventoryUI.h"

Inventory::~Inventory()
{
	for (int i = 0; i < m_items.size(); i++)
	{
		delete m_items[i];
	}
	m_items.clear();
	delete m_inventoryUI;
}

void Inventory::AddItem(Item* item)
{
	bool containsItem = std::find(m_items.begin(), m_items.end(), item) != m_items.end();

	if (containsItem && item->IsStackable())
	{
		item->IncrementStackSize();
	}
	else
	{
		m_items.push_back(item);
	}

	item->UpdateOwner(this);
	item->OnAdded();
	OnItemAdded(item);
}

void Inventory::RemoveItem(Item* item)
{
	bool containsItem = std::find(m_items.begin(), m_items.end(), item) != m_items.end();

	//vector does not contain item, stop here...
	if (!containsItem) return;

	if (item->IsStackable())
	{
		if (item->GetStackSize() <= 1) 
		{
			m_items.erase(std::remove(m_items.begin(), m_items.end(), item), m_items.end());
		}
		else
		{
			item->DecrementStackSize();
		}
	}
	else
	{
		m_items.erase(std::remove(m_items.begin(), m_items.end(), item), m_items.end());
	}

	item->UpdateOwner(nullptr);
	item->OnRemoved();
	OnItemRemoved(item);
}

bool Inventory::ContainsItem(Item* item)
{
	return std::find(m_items.begin(), m_items.end(), item) != m_items.end();
}

bool Inventory::IsFull()
{
	if (m_items.size() >= m_maxSlots)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

int Inventory::GetRemainingSlots()
{
	return m_maxSlots - m_items.size();
}

int Inventory::GetTakenSlots()
{
	return m_items.size();
}

int Inventory::CountMoney()
{
	int count = 0;
	for (int i = 0; i < m_items.size(); i++)
	{
		auto money = dynamic_cast<MoneyItem*>(m_items[i]);
		if (money != nullptr)
			count += money->GetStackSize();
	}

	return count;
}

void Inventory::Draw(CRenderer* renderer)
{
	if (m_inventoryUI == nullptr) 
	{
		m_inventoryUI = new InventoryUI(renderer);
		UpdateUIElements();
	}
	m_inventoryUI->Draw();
}

std::vector<Item*> Inventory::GetItems()
{
	return m_items;
}

WorldObject* Inventory::GetOwner()
{
	return m_owner;
}

int Inventory::GetMaxSlots()
{
	return m_maxSlots;
}

void Inventory::UpdateUIElements()
{
	UILabelBuilder labelbuilder = *(UILabelBuilder*)m_inventoryUI->GetUIFactory()->getBuilder<Label>("Label");
	for (int i = 0; i < GetItems().size(); i++)
	{
		auto item = GetItems()[i];
		m_inventoryUI->AddElement(labelbuilder.withText(item->GetName()).withPosition(0, i * 50).build());
	}
}
