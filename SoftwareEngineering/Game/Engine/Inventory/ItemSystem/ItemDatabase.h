#pragma once
#include <string>
#include <vector>
#include <map>
class Item;

class ItemDatabase
{
private:
	std::vector<Item*> m_itemList;
	static ItemDatabase* m_instance;
public:
	static void Init(std::string dbFile);
	static Item* GetItemByID(std::string id);
	static ItemDatabase* getInstance() { return m_instance; }
	static void DeleteInstance();

	~ItemDatabase();
};
