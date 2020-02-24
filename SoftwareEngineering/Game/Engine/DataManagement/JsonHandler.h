#pragma once
#include <string>

class JsonHandler
{
private:
	static std::string GetSubString(const std::string& str, char c);
	template<typename T>
	static std::string ConvertToString(T val);
	static std::string ReadJson(const char* filename, const char* objectID, const char* key);
	void WriteJson(const char* filename, const char* objectID, const char* key, const char* val);
	
public:
	JsonHandler();
	~JsonHandler();

	void ReadValue(const char* filename, const char* objectID, const char* key, int* val);
	void ReadValue(const char* filename, const char* objectID, const char* key, bool* val);
	void ReadValue(const char* filename, const char* objectID, const char* key, float* val);
	void ReadValue(const char* filename, const char* objectID, const char* key, std::string* val);

	// TODO: Implement Writing Json Files
	void WriteValue(const char* filename, const char* objectID, const char* key, int val);
	void WriteValue(const char* filename, const char* objectID, const char* key, bool val);
	void WriteValue(const char* filename, const char* objectID, const char* key, float val);
	void WriteValue(const char* filename, const char* objectID, const char* key, std::string val);
};