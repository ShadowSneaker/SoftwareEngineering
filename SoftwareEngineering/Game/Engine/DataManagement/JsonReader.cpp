#include "JsonReader.h"
#include <iostream>

void JsonReader::GetValue(const std::string& path, const std::string& obj, const std::string& key, int* val)
{
	const std::string valString = ReadValue(path, obj, key);
	if (!IsDigit(valString) || valString.empty())
	{
		std::cout << "Value of " << key << " is NaN";
		return;
	}
	*val = std::stoi(valString);
}

void JsonReader::GetValue(const std::string& path, const std::string& obj, const std::string& key, float* val)
{
	const std::string valString = ReadValue(path, obj, key);
	if (!IsDigit(valString) || valString.empty())
	{
		std::cout << "Value of " << key << " is NaN";
		return;
	}
	*val = std::stof(valString);
}

void JsonReader::GetValue(const std::string& path, const std::string& obj, const std::string& key, bool* val)
{
	const std::string valString = ReadValue(path, obj, key);
	*val = valString == "true," || valString == "true";
}

void JsonReader::GetValue(const std::string& path, const std::string& obj, const std::string& key, std::string* val)
{
	*val = GetSubString(ReadValue(path, obj, key), '"', '"', 0);
}

std::vector<std::string> JsonReader::GetAllKeys(const std::string& path, const std::string& obj) const
{
	JsonObject* jsonObject = GetObject(path, obj);
	return jsonObject->GetAllElementKeys();
}

JsonObject* JsonReader::GetObject(const std::string& path, const std::string& obj) const
{
	std::ifstream file;
	file.open(path, std::ios::out);

	if (file.fail())
	{
		std::cout << "Could not open " << path << std::endl;
		return new JsonObject("");
	}

	bool keyFound = false;
	std::string jsonString;

	for (std::string line; std::getline(file, line); )
	{
		std::string sub = line.substr(0, 1);

		if (!keyFound)
		{
			if (!line.empty() && sub != "\t" && sub != "{" && sub != "}")
			{
				std::string key = line.substr(0, line.find_first_of(' '));

				if (key == obj)
				{
					jsonString += line + "\n";
					keyFound = true;
				}
			}
		}
		else
		{
			jsonString += line + "\n";
			if (sub == "}")
			{
				break;
			}
		}
	}

	if (!keyFound)
	{
		std::cout << "Object " << obj << " not found" << std::endl;
	}

	return new JsonObject(jsonString);
}

std::string JsonReader::ReadValue(const std::string& path, const std::string& objectString, const std::string& key)
{
	JsonObject* jsonObject = GetObject(path, objectString);
	const std::string jsonString = jsonObject->Get();
	const size_t startPos = GetKeyPos(jsonString, key);
	if (startPos == std::string::npos)
	{
		std::cout << "Key " << key << " not found" << std::endl;
		return "";
	}
	std::string sub = jsonString.substr(startPos, jsonString.length() - startPos);
	std::string valString = GetSubString(sub, ':', '\n');

	return valString;
}

size_t JsonReader::GetKeyPos(const std::string& objectString, const std::string& key)
{
	const size_t pos = objectString.find("\t\"" + key + "\":");
	return pos;
}

std::string JsonReader::GetSubString(const std::string& str, char start, char end, int startOffset)
{
	const auto position = str.find(start) + startOffset;
	const auto position2 = str.find(end, position + 1);
	auto sub = str.substr(position + 1, position2 - position - 1);

	return sub;
}

bool JsonReader::IsDigit(const std::string& s)
{
	return s.find_first_not_of("0123456789-,. ") == std::string::npos;
}
