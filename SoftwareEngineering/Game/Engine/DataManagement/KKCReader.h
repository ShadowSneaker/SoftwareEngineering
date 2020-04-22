#pragma once
#include <string>
#include <vector>
class KKCReader
{
public:
	KKCReader(std::string filePath);
	std::string fileText;
	std::string ReadValue(std::string object, std::string key);

	std::vector<std::string> items;
private: 
	void InitItems();
	std::string GetArray(std::string key);
	bool IsMoreNested(std::string s, int pos);
};

