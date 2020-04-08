#pragma once
#include "fstream"
#include <iostream>
#include <fstream>
#include <string>

class TextFileReadWrite
{
private:

public:
	//Constructor
	TextFileReadWrite();
	//Deconstructor
	~TextFileReadWrite();
	//Reading out a Value as const char* (so that users can then further use it) with he help of a key.
	const char* ReadFile(const char* filename, const char* key);
	//Template to be able to use generics
	template <typename T>
	//Writing generic Value into a file or even creating a new one if not yet existing. Using a Key to later take out the Value again
	void WriteFile(T t, const char* filename, const char* key);
};

template <typename T>
void TextFileReadWrite::WriteFile(T t, const char* filename, const char* key)
{
	typename std::ofstream myfile(filename, std::ios::app);
	if (myfile.is_open())
	{
		myfile << key << ":" << t << ", ";
		myfile.close();
	}
};

