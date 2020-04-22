#pragma once
#include "JsonObject.h"
#include "JsonHandler.h"

class JsonWriter : public JsonHandler
{
public:
	// Creates a new File and adds the given Object
	void WriteNew(const std::string& path, JsonObject* obj);
	// Appends an object to a file if the id is not duplicate, also creates a new file if it does not exist
	void Append(const std::string& path, JsonObject* obj);

private:
	size_t m_curPos = -1;
	int m_indent = 0;
	// Beautifies the string to match the desired JSON structure
	std::string Beautify(const std::string& jsonString);
	std::string GetLineSubString(const std::string& str, char c);
	std::string GetIndent() const;
	// Writes or Appends the JSON string to a file
	void WriteToFile(const std::string& path, JsonObject* obj, std::ios::openmode mode);
};
