#pragma once
#include "JsonBase.h"
#include <vector>

class JsonObject : public JsonBase
{
public:
	// Creates a JsonObject from file-string or a list of JsonBase attributes
	JsonObject(const std::string& jsonString);
	JsonObject(std::string id, std::vector<JsonBase*> attributes);
	// Returns the ID of the object
	std::string GetID() const;
	// Returns all element keys of the object
	std::vector<std::string> GetAllElementKeys() const;

private:
	std::string m_id;
	std::vector<JsonBase*> m_attributes;

	// Builds the object from the given parameters
	void BuildObject();
};
