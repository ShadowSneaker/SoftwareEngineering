#pragma once
#include <fstream>
#include <vector>

class JsonHandler
{
public:
	~JsonHandler() = default;
	// Returns all object ids of a file
	virtual std::vector<std::string> GetAllObjectIds(const std::string& path);
};
