#pragma once
#include "JsonHandler.h"
#include "JsonObject.h"

class JsonReader : public JsonHandler
{
public:
	// Read value methods to set a value by passing the variable as pointer
	void GetValue(const std::string& path, const std::string& obj, const std::string& key, int* val);
	void GetValue(const std::string& path, const std::string& obj, const std::string& key, float* val);
	void GetValue(const std::string& path, const std::string& obj, const std::string& key, bool* val);
	void GetValue(const std::string& path, const std::string& obj, const std::string& key, std::string* val);
	// Returns all keys of a JsonObject
	std::vector<std::string> GetAllKeys(const std::string& path, const std::string& obj) const;
	friend class JsonObject;
private:
	// Creates a JsonObject from a given string
	JsonObject* GetObject(const std::string& path, const std::string& obj) const;
	// Reads the value
	std::string ReadValue(const std::string& path, const std::string& objectString, const std::string& key);
	// Returns the position of the key in the object string
	static size_t GetKeyPos(const std::string& objectString, const std::string& key);
	// Returns the substring between two given chars
	static std::string GetSubString(const std::string& str, char start, char end, int startOffset = 1);
	// Checks if an int or float variable is valid
	bool IsDigit(const std::string& s);
};