#pragma once
#include "../Inventory/ItemSystem/Item.h"
#include <map>
#include <SDL.h>
#include "../Input/KeyboardInput.h"
#include "../WorldObject/WorldObject.h"

class JsonFacade
{
public:
	JsonFacade();
	~JsonFacade();
	//void WriteItem(const std::string& path, const std::string& id, Item item);
	// Writes values of an item to a JSON file
	void WriteItem(const std::string& path, const std::string& id, const std::string& name, 
		const std::string& iconPath, bool isQuestItem, bool isStackable, int value, int weight);
	// Writes a keyboard setup to a JSON file
	void WriteKeyboardSetup(const std::string& path, const std::string& id, const std::map<KEY_LIST, SDL_Keycode>& keyboardSetup);
	// Returns a keyboard setup from a file
	std::map<KEY_LIST, SDL_Keycode> ReadKeyBoardSetup(const std::string& path, const std::string& id);
	// Writes a WorldObject to JSON file
	void WriteWorldObject(const std::string& path, const std::string& id, WorldObject worldObject);
	// Returns a WorldObject from a file
	WorldObject ReadWorldObject(const std::string& path, const std::string& id);
};