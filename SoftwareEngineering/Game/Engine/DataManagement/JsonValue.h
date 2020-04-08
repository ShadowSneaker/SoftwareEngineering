#pragma once
#include "JsonBase.h"
#include "typeinfo"

class JsonValue : public JsonBase
{
public:
	// Creates a key value pair of a given key and generic value
	template<typename T>
	JsonValue(const std::string& key, T value);
	JsonValue(const std::string& jsonString);
};

inline JsonValue::JsonValue(const std::string& jsonString)
{
	m_val = jsonString;
}

template <typename T>
JsonValue::JsonValue(const std::string& key, T value)
{
	std::string val = ConvertToString(value);

	if (typeid(value) == typeid(bool))
	{
		val = val == "0" ? "false" : "true";
	}

	if (typeid(value) == typeid(std::string) || typeid(value) == typeid(const char*))
	{
		val = AddQuotes(val);
	}

	m_val = "\"" + key + "\": " + val + ",\n";
}