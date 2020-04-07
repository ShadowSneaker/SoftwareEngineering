#include "JsonObject.h"
#include <utility>
#include <typeinfo>
#include "JsonValue.h"
#include <iostream>
#include "JsonArray.h"
#include "JsonReader.h"

JsonObject::JsonObject(const std::string& jsonString)
{
	m_val = jsonString;
}

JsonObject::JsonObject(std::string id, std::vector<JsonBase*> attributes)
{
	m_id = std::move(id);
	m_attributes = std::move(attributes);
	BuildObject();
}

void JsonObject::BuildObject()
{
	m_val = m_id + " = {\n";

	for (std::string::size_type i = 0; i < m_attributes.size(); i++)
	{
		JsonBase* base = m_attributes[i];
		std::string val = base->Get();

		if (i == m_attributes.size() - 1 && typeid(*base) == typeid(JsonValue)) 
		{
			val.erase(val.length() - 2, 1);
		}

		m_val += val;
	}

	m_val += "}\n";
}

std::string JsonObject::GetID() const
{
	return m_id;
}

std::vector<std::string> JsonObject::GetAllElementKeys() const
{
	std::vector<std::string> keys;
	std::istringstream stream(m_val);

	for (std::string line; std::getline(stream, line); )
	{
		if (line.find("\": ") != std::string::npos)
		{
			std::string key = JsonReader::GetSubString(line, '"', '"', 0);
			keys.push_back(key);
		}
	}

	return keys;
}
