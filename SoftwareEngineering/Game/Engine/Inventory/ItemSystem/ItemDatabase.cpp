#include "ItemDatabase.h"
#include "Consumable.h"
#include "Switchable.h"
#include "Equippable.h"
#include "MoneyItem.h"
#include "../../DataManagement/KKCReader.h"

ItemDatabase* ItemDatabase::m_instance = nullptr;
static enum ItemTypeValues {
	vNotDefined,
	vConsumable,
	vSwitchable,
	vEquippable,
	vMoneyItem
};

static std::map<std::string, ItemTypeValues> s_mapItemTypeValues;

void ItemDatabase::Init(std::string dbFile)
{
	s_mapItemTypeValues["Consumable"] = vConsumable;
	s_mapItemTypeValues["Switchable"] = vSwitchable;
	s_mapItemTypeValues["Equippable"] = vEquippable;
	s_mapItemTypeValues["MoneyItem"] = vMoneyItem;
	m_instance = new ItemDatabase;
	int itemType = 0;
	KKCReader reader(dbFile);
	for (int i = 0; i < reader.items.size(); i++)
	{
		switch (s_mapItemTypeValues[reader.ReadValue(reader.items[i], "Type")])
		{
		case vConsumable: 
		{
			Consumable* consumable;
			consumable = new Consumable;
			consumable->SetID(reader.ReadValue(reader.items[i], "Id"));
			consumable->SetName(reader.ReadValue(reader.items[i], "Name"));
			consumable->SetValue(stoi(reader.ReadValue(reader.items[i], "m_value")));
			consumable->SetWeight(stoi(reader.ReadValue(reader.items[i], "m_weight")));
			
			consumable->SetIsQuestItem(reader.ReadValue(reader.items[i], "m_isQuestItem") == "True");
			
			consumable->SetIsStackable(reader.ReadValue(reader.items[i], "m_stackable") == "True");
			
			m_instance->m_itemList.push_back(consumable);
			break;
		}
		case vSwitchable:
		{
			Switchable* switchable;
			switchable = new Switchable;
			switchable->SetID(reader.ReadValue(reader.items[i], "Id"));
			switchable->SetName(reader.ReadValue(reader.items[i], "Name"));
			switchable->SetValue(stoi(reader.ReadValue(reader.items[i], "m_value")));
			switchable->SetWeight(stoi(reader.ReadValue(reader.items[i], "m_weight")));
			
			switchable->SetIsQuestItem(reader.ReadValue(reader.items[i], "m_isQuestItem") == "True");
			
			switchable->SetIsStackable(reader.ReadValue(reader.items[i], "m_stackable") == "True");
			
			m_instance->m_itemList.push_back(switchable);
			break;
		}
		case vEquippable:
		{
			Equippable* equippable;
			equippable = new Equippable;
			equippable->SetID(reader.ReadValue(reader.items[i], "Id"));
			equippable->SetName(reader.ReadValue(reader.items[i], "Name"));
			equippable->SetValue(stoi(reader.ReadValue(reader.items[i], "m_value")));
			equippable->SetWeight(stoi(reader.ReadValue(reader.items[i], "m_weight")));
			
			equippable->SetIsQuestItem(reader.ReadValue(reader.items[i], "m_isQuestItem") == "True");
			
			equippable->SetIsStackable(reader.ReadValue(reader.items[i], "m_stackable") == "True");
			
			m_instance->m_itemList.push_back(equippable);
			break;
		}
		case vMoneyItem:
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
	
	//add items to itemList
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
