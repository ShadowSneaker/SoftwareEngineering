#pragma once
#include "JsonBase.h"
#include <vector>
#include <list>
#include <map>

class JsonArray : public JsonBase
{
public:
	// Creates a JsonArray of generic values, Objects or Arrays
	template<typename T>
	JsonArray(const std::string& key, std::vector<T> values);
	JsonArray(const std::string& key, const std::vector<JsonObject*>& values);
	JsonArray(const std::string& key, const std::vector<JsonArray*>& values);
	template<typename T>
	JsonArray(const std::string& key, std::list<T> values);
	template<typename TKey, typename TValue>
	JsonArray(const std::string& key, std::map<TKey, TValue> values);
	template<typename T>
	JsonArray(const std::string& key, T values[]);

private:
	void AddJsonString(JsonBase* value);
};

inline JsonArray::JsonArray(const std::string& key, const std::vector<JsonObject*>& values)
{
	m_val = AddQuotes(key) + ": [\n";
	for (auto value : values)
	{
		AddJsonString(value);
	}
	m_val += "]\n";
}

inline JsonArray::JsonArray(const std::string& key, const std::vector<JsonArray*>& values)
{
	m_val = AddQuotes(key) + ": [\n";
	for (auto value : values)
	{
		AddJsonString(value);
	}
	m_val += "]\n";
}

inline void JsonArray::AddJsonString(JsonBase* value)
{
	m_val += value->Get();
}

template <typename T>
JsonArray::JsonArray(const std::string& key, std::vector<T> values)
{
	m_val = AddQuotes(key) + ": [\n";

	for (int i = 0; i < values.size(); i++)
	{
		std::string val = ConvertToString(values[i]);
		if (typeid(values[i]) == typeid(std::string) || typeid(values[i]) == typeid(const char*))
		{
			val = AddQuotes(val);
		}
		m_val += val;
		if (i < values.size() - 1)
		{
			m_val += ",";
		}
		m_val += "\n";
	}
	m_val += "]\n";
}


// Not yet implemented
template <typename T>
JsonArray::JsonArray(const std::string& key, std::list<T> values)
{

}

template <typename TKey, typename TValue>
JsonArray::JsonArray(const std::string& key, std::map<TKey, TValue> values)
{
}

template <typename T>
JsonArray::JsonArray(const std::string& key, T values[])
{
}
