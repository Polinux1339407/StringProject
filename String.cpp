#include "String.h"

String::String()
{
	size = 0;
	data = new char[1];
	data[0] = '\0';
}

String::String(const char* c_str)
{
	size = strlen(c_str);
	data = new char[size + 1];
	std::copy(c_str, c_str + size, data);
	data[size] = '\0';
}

String::String(const String& other)
{
	size = other.size;
	data = new char[size + 1];
	std::copy(other.data, other.data + other.size, data);
	data[size] = '\0';
}

String::String(String&& other) throw()
{
	size = other.size;
	data = other.data;
	other.data = nullptr;
	other.size = 0;
}

String::~String()
{
	delete[] data;
}

char* String::c_str() const
{
	return data;
}

size_t String::length() const
{
	return size;
}

String& String::operator=(const String& other)
{
	if (&other != this)
	{
		delete[] data;
		size = other.size;
		data = new char[size + 1];
		std::copy(other.data, other.data + other.size, data);
	}
	return *this;
}

String& String::operator=(String&& other) throw()
{
	if (&other != this)
	{
		delete[] data;
		size = other.size;
		data = other.data;
		other.size = 0;
		other.data = nullptr;
	}
	return *this;
}

String& String::operator=(const char* c_str)
{
	delete[] data;
	size = strlen(c_str);
	data = new char[size + 1];
	std::copy(c_str, c_str + size, data);
	data[size] = '\0';
	return *this;
}

String& String::operator+=(const String& other)
{
	char* new_data = new char[size + other.size + 1];
	std::copy(data, data + size, new_data);
	std::copy(other.data, other.data + other.size, new_data + size);
	size += other.size;
	delete[] data;
	data = new_data;
	data[size] = '\0';
	return *this;
}

String& String::operator+=(const char* c_str)
{
	size_t str_size = strlen(c_str);
	char* new_data = new char[size + str_size + 1];
	std::copy(data, data + size, new_data);
	std::copy(c_str, c_str + str_size, new_data + size);
	size += str_size;
	delete[] data;
	data = new_data;
	data[size] = '\0';
	return *this;
}

String operator+(const String& lvalue, const String& rvalue)
{
	return String(lvalue) += rvalue;
}

String operator+(const String& lvalue, const char* rvalue)
{
	return String(lvalue) += String(rvalue);
}

std::ostream& operator<<(std::ostream& os, const String& str)
{
	os << str.data;
	return os;
}

char String::operator[](unsigned index) const
{
	return data[index];
}

bool String::operator<(const String& other) const
{
	return std::lexicographical_compare(data, data + size,
		other.data, other.data + other.size,
		[](char c1, char c2) { return std::tolower(c1) < std::tolower(c2); });
}

bool String::operator>(const String& other) const
{
	return other < *this;
}
