#include "JsonFacade.h"
#include "JsonBase.h"
#include "JsonObject.h"
#include "JsonArray.h"
#include "JsonValue.h"
#include "JsonWriter.h"
#include "JsonReader.h"

JsonFacade::JsonFacade()
= default;

JsonFacade::~JsonFacade()
= default;

//void JsonFacade::WriteItem(const std::string & path, const std::string & id, Item item)
//{
//	std::vector<JsonBase*> elements;
//	elements.push_back(new JsonValue("id", item.GetID()));
//	elements.push_back(new JsonValue("name", item.GetName()));
//	elements.push_back(new JsonValue("name", item.GetIconPath()));
//}

void JsonFacade::WriteItem(const std::string & path, const std::string & id, const std::string & name,
	const std::string & iconPath, bool isQuestItem, bool isStackable, int value, int weight)
{
	std::vector<JsonBase*> elements;
	elements.push_back(new JsonValue("id", id));
	elements.push_back(new JsonValue("name", name));
	elements.push_back(new JsonValue("icon", iconPath));
	elements.push_back(new JsonValue("isQuestItem", isQuestItem));
	elements.push_back(new JsonValue("isStackable", isStackable));
	elements.push_back(new JsonValue("value", value));
	elements.push_back(new JsonValue("weight", weight));

	JsonObject* itemObject = new JsonObject(id, elements);

	JsonWriter* writer = new JsonWriter();
	writer->Append(path, itemObject);
}

void JsonFacade::WriteKeyboardSetup(const std::string & path, const std::string & id, const std::map<KEY_LIST, SDL_Keycode>& keyboardSetup)
{
	std::vector<JsonBase*> elements;

	for (const std::pair<KEY_LIST, SDL_Keycode> pair : keyboardSetup)
	{
		const int i = pair.first;
		elements.push_back(new JsonValue(std::to_string(i), pair.second));
	}

	JsonObject* keyboardObject = new JsonObject(id, elements);

	JsonWriter* writer = new JsonWriter();
	writer->Append(path, keyboardObject);
}

std::map<KEY_LIST, SDL_Keycode> JsonFacade::ReadKeyBoardSetup(const std::string & path, const std::string & id)
{
	JsonReader* reader = new JsonReader();
	std::map<KEY_LIST, SDL_Keycode> keybinds;

	std::vector<std::string> keys = reader->GetAllKeys(path, id);

	for (const std::string& key : keys)
	{
		KEY_LIST key_type = static_cast<KEY_LIST>(std::stoi(key));
		int val;
		reader->GetValue(path, id, key, &val);
		const SDL_Keycode keycode = static_cast<SDL_Keycode>(val);
		keybinds[key_type] = keycode;
	}

	return keybinds;
}

void JsonFacade::WriteWorldObject(const std::string & path, const std::string & id, WorldObject worldObject)
{
	std::vector<JsonBase*> elements;
	elements.push_back(new JsonValue("posX", worldObject.Position().GetX()));
	elements.push_back(new JsonValue("posY", worldObject.Position().GetY()));
	elements.push_back(new JsonValue("posZ", worldObject.Position().GetZ()));
	elements.push_back(new JsonValue("scaleX", worldObject.Scale().GetX()));
	elements.push_back(new JsonValue("scaleY", worldObject.Scale().GetY()));
	elements.push_back(new JsonValue("heading", worldObject.Heading()));
	elements.push_back(new JsonValue("id", worldObject.GetId()));
	elements.push_back(new JsonValue("isActive", worldObject.IsActive()));

	JsonObject* worldObj = new JsonObject(id, elements);

	JsonWriter* writer = new JsonWriter();
	writer->Append(path, worldObj);
}

WorldObject JsonFacade::ReadWorldObject(const std::string & path, const std::string & id)
{
	JsonReader* reader = new JsonReader();

	float posX, posY, posZ;
	reader->GetValue(path, id, "posX", &posX);
	reader->GetValue(path, id, "posY", &posY);
	reader->GetValue(path, id, "posZ", &posZ);
	const SVector3 pos(posX, posY, posZ);

	float scaleX, scaleY;
	reader->GetValue(path, id, "scaleX", &scaleX);
	reader->GetValue(path, id, "scaleY", &scaleY);
	const SVector2 scale(scaleX, scaleY);

	float heading;
	reader->GetValue(path, id, "heading", &heading);

	int objId;
	reader->GetValue(path, id, "id", &objId);

	bool isActive;
	reader->GetValue(path, id, "isActive", &isActive);

	const WorldObject worldObj(pos, heading, scale, objId, isActive);

	return worldObj;
}
