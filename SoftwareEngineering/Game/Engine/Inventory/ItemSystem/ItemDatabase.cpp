#include "ItemDatabase.h"
#include "Consumable.h"
#include "Switchable.h"
#include "Equippable.h"
#include "MoneyItem.h"

ItemDatabase* ItemDatabase::m_instance = nullptr;

void ItemDatabase::Init(std::string dbFile)
{
	m_instance = new ItemDatabase;
	int itemType = 0;

	//add items to itemList
	switch (itemType)
	{
	case '1': 
	{
		Consumable* consumable;
		consumable = new Consumable;
		m_instance->m_itemList.push_back(consumable);
		break;
	}
	case '2':
	{
		Switchable* switchable;
		switchable = new Switchable;
		m_instance->m_itemList.push_back(switchable);
		break;
	}
	case '3':
	{
		Equippable* equippable;
		equippable = new Equippable;
		m_instance->m_itemList.push_back(equippable);
		break;
	}
	case '4':
	{
		MoneyItem* moneyItem;
		moneyItem = new MoneyItem;
		m_instance->m_itemList.push_back(moneyItem);
		break;
	}
	default:
		break;
	}
}

Item* ItemDatabase::GetItemByID(std::string id)
{
	if (m_instance != nullptr)
	{

		for (int i = 0; i < m_instance->m_itemList.size(); i++)
		{
			if(m_instance->m_itemList[i]->GetID() == id)
			{
				return m_instance->m_itemList[i]->Clone();
			}
		}
	}
	
	return nullptr;
}

void ItemDatabase::DeleteInstance()
{
	delete m_instance;
	m_instance = nullptr;
}

ItemDatabase::~ItemDatabase()
{
	for (int i = 0; i < m_itemList.size(); i++)
	{
		delete m_itemList[i];
	}

	m_itemList.clear();
}
