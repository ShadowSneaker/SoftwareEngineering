#pragma once
#include <string>
#include <sstream>

class JsonBase
{
protected:
	std::string m_val;

	// Converts the generic type to string
	template<typename T>
	static std::string ConvertToString(T val);
	// Adds quotes around a given string
	static std::string AddQuotes(const std::string& s);

public:
	virtual ~JsonBase() = 0;
	virtual std::string Get() const;
};

inline std::string JsonBase::AddQuotes(const std::string& s)
{
	return "\"" + s + "\"";
}

inline JsonBase::~JsonBase()
= default;

inline std::string JsonBase::Get() const
{
	return m_val;
}

template <typename T>
std::string JsonBase::ConvertToString(T val)
{
	std::ostringstream ss;
	ss << val;
	const std::string str_val(ss.str());
	return str_val;
}
