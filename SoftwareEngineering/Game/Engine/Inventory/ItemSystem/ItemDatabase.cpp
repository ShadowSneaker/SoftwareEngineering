#include "ItemDatabase.h"
#include "Item.h"
#include "Consumable.h"
#include "Switchable.h"
#include "Equippable.h"

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
		//
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
				return m_instance->m_itemList[i];
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
