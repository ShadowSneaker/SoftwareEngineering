#include "JsonHandler.h"
#include <string>
#include <iostream>

std::vector<std::string> JsonHandler::GetAllObjectIds(const std::string& path)
{
	std::vector<std::string> ids;

	std::ifstream file;
	file.open(path, std::ios::out);

	if (file.fail())
	{
		std::cout << "Could not open " << path << std::endl;
		return ids;
	}

	for (std::string line; std::getline(file, line); )
	{
		std::string sub = line.substr(0, 1);

		if (!line.empty() && sub != "\t" && sub != "{" && sub != "}")
		{
			std::string id = line.substr(0, line.find_first_of(' '));
			ids.push_back(id);
		}
	}

	return ids;
}
