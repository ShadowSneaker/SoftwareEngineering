#include "JsonHandler.h"
#include <fstream>
#include <iostream>
#include <string>
#include <limits>
#include <sstream>

using namespace std;

JsonHandler::JsonHandler()
{

}

JsonHandler::~JsonHandler()
{
	
}

void JsonHandler::ReadValue(const char* filename, const char* objectID, const char* key, int* val)
{
	const std::string str_val = ReadJson(filename, objectID, key);
	*val = str_val.empty() ? numeric_limits<int>::min() : stoi(str_val);
}

void JsonHandler::ReadValue(const char* filename, const char* objectID, const char* key, bool* val)
{
	const std::string str_val = ReadJson(filename, objectID, key);
	*val = str_val == "true";
}

void JsonHandler::ReadValue(const char* filename, const char* objectID, const char* key, float* val)
{
	const std::string str_val = ReadJson(filename, objectID, key);
	*val = str_val.empty() ? numeric_limits<float>::min() : stof(str_val);
}

void JsonHandler::ReadValue(const char* filename, const char* objectID, const char* key, std::string* val)
{
	*val = ReadJson(filename, objectID, key);
}

void JsonHandler::WriteValue(const char* filename, const char* objectID, const char* key, int val)
{
	WriteJson(filename, objectID, key, ConvertToString(val).c_str());
}

void JsonHandler::WriteValue(const char* filename, const char* objectID, const char* key, bool val)
{

}

void JsonHandler::WriteValue(const char* filename, const char* objectID, const char* key, float val)
{
	WriteJson(filename, objectID, key, ConvertToString(val).c_str());
}

template<typename T>
std::string JsonHandler::ConvertToString(T val)
{
	std::ostringstream ss;
	ss << val;
	const std::string str_val(ss.str());
	return str_val;
}


void JsonHandler::WriteValue(const char* filename, const char* objectID, const char* key, std::string val)
{
	const std::string str_val = "\"" + val + "\"";
	WriteJson(filename, objectID, key, str_val.c_str());
}

std::string JsonHandler::ReadJson(const char* filename, const char* objectID, const char* key)
{
	ifstream file;
	file.open(filename, ios::out);
	
	if (file.fail()) 
	{
		cout << "Could not open " << filename << std::endl;
		return "";
	}

	std::string input;

	while (!(input == objectID))
	{
		if (!(file >> input))
		{
			cout << "Object " << objectID << " not found";
			return "";
		}
	}

	while (file >> input) 
	{
		std::string sub = GetSubString(input, '"');
		if (key == sub)
		{
			file >> input;
			sub = GetSubString(input, '"');
			return sub;
		}
	}

	cout << "Key " << key << " not found";

	return "";
}

void JsonHandler::WriteJson(const char* filename, const char* objectID, const char* key, const char* val)
{
	ofstream file;
	file.open(filename, ios::app);

	if (file.fail())
	{
		std::cout << "Could not open " << filename << std::endl;
	}

	file << objectID << " = {\n\t\"" << key << "\": " << val << ",";
	file.close();
}


std::string JsonHandler::GetSubString(const std::string& str, char c)
{
	const auto position = str.find(c);
	const auto position2 = str.find(c, position + 1);
	auto sub = str.substr(position + 1, position2 - position - 1);

	return sub;
}

//template const char* JsonHandler::ConvertToString<int>(int);
//template const char* JsonHandler::ConvertToString<float>(float);