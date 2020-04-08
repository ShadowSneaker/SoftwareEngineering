#include "JsonWriter.h"
#include <iostream>
#include <fstream>

void JsonWriter::WriteNew(const std::string& path, JsonObject* obj)
{
	WriteToFile(path, obj, std::ios::out);
}

void JsonWriter::Append(const std::string& path, JsonObject* obj)
{
	std::vector<std::string> objectsIds = GetAllObjectIds(path);
	if (std::find(objectsIds.begin(), objectsIds.end(), obj->GetID()) != objectsIds.end())
	{
		std::cout << "Duplicate ID";
	}
	else
	{
		WriteToFile(path, obj, std::ios::app);
	}
}

std::string JsonWriter::Beautify(const std::string& jsonString)
{
	std::string json;

	while (true)
	{
		std::string line = GetLineSubString(jsonString, '\n');

		if (line.find(']') != std::string::npos || line.find('}') != std::string::npos)
		{
			m_indent--;
		}

		json += GetIndent() + line;

		if (line.find('[') != std::string::npos || line.find('{') != std::string::npos)
		{
			m_indent++;
		}

		if (line.empty())
		{
			break;
		}

		if (m_indent == 0)
		{
			json += "\n";
		}
	}

	return json;
}

std::string JsonWriter::GetLineSubString(const std::string& str, char c)
{
	const auto position2 = str.find(c, m_curPos + 1);
	auto sub = str.substr(m_curPos + 1, position2 - m_curPos);
	m_curPos = position2;

	return sub;
}

std::string JsonWriter::GetIndent() const
{
	std::string s;
	for (int i = 0; i < m_indent; i++)
	{
		s += "\t";
	}
	return s;
}

void JsonWriter::WriteToFile(const std::string& path, JsonObject* obj, std::ios::openmode mode)
{
	const std::string fileString = Beautify(obj->Get());
	std::ofstream file;
	file.open(path, mode);

	if (file.fail())
	{
		std::cout << "Could not open " << path << std::endl;
	}

	file << fileString;
	file.close();
}
