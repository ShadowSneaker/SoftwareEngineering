#include "TextFileReadWrite.h"

TextFileReadWrite::TextFileReadWrite()
{

}

TextFileReadWrite::~TextFileReadWrite()
{

}

const char* TextFileReadWrite::ReadFile(const char* filename,const char* key)
{
	std::string line;
	std::string myString;
	std::ifstream myfile(filename);
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			myString += line;
		}
		std::size_t KeyPos = myString.find(key);
		std::size_t KeyPosStart = myString.find(":", KeyPos);
		std::size_t KeyPosEnd = myString.find(",");
		std::string finalString = myString.substr(KeyPosStart + 1, KeyPosEnd - (KeyPosStart + 1));
		std::cout << finalString.c_str();
		return finalString.c_str();
		myfile.close();
	}
}