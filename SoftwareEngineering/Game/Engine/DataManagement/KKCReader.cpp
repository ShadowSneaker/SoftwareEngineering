#include "KKCReader.h"
#include <fstream>
#include <streambuf>
#include <iostream>

KKCReader::KKCReader(std::string filePath)
{
	std::ifstream file;
	file.open(filePath, std::ios::out);

	if (file.fail())
	{
		std::cout << "Could not open " << filePath << std::endl;
	}

	for (std::string line; std::getline(file, line); )
	{
		fileText += line;
	}

	InitItems();
}

std::string KKCReader::ReadValue(std::string object, std::string key)
{
	auto pos = object.find(key);

	if (pos != std::string::npos)
	{
		auto a = object.find_first_of('"', pos + key.length() + 1);
		auto b = object.find_first_of('"', a + 2);


		return object.substr(a + 2, b - 1 - a);
	}
	return std::string();
}

void KKCReader::InitItems()
{
	std::string allItems = GetArray("Items");

	auto currentItem = allItems.find("Type");
	auto nextItem = allItems.find("\"Type\"", currentItem + 4);

	while (nextItem != std::string::npos)
	{
		items.push_back(allItems.substr(currentItem, nextItem - 2 - currentItem));
		currentItem = nextItem;
		nextItem = allItems.find("\"Type\"", currentItem + 2);
	}
	items.push_back(allItems.substr(currentItem, allItems.length() - currentItem - 2));
}

std::string KKCReader::GetArray(std::string key)
{
	auto pos = fileText.find(key);

	if (pos != std::string::npos)
	{
		auto a = fileText.find('[', pos);
		auto b = fileText.find("Inventories", pos); 

		return fileText.substr(a, b - 2 - a);
	}
	return std::string();
}

bool KKCReader::IsMoreNested(std::string s, int pos)
{
	auto nextOpening = s.find("{");
	auto nextClosing = s.find("}");

	return nextOpening < nextClosing;
}



