#include "String.h"

String::String() // Default constructor
{
	size = 0;
	data = new char[1];
	data[0] = '\0';
}

String::String(const char* cStr) // Constructor for a sequence of characters
{
	size = strlen(cStr);
	data = new char[size + 1];
	std::copy(cStr, cStr + size, data);
	data[size] = '\0';
}

String::String(const String& other) // Copy constructor
{
	size = other.size;
	data = new char[size + 1];
	std::copy(other.data, other.data + other.size, data);
	data[size] = '\0';
}

String::String(String&& other) throw() // Move constructor
{
	size = other.size;
	data = other.data;
	other.data = nullptr;
	other.size = 0;
}

String::~String() // Destructor
{
	delete[] data;
}

char* String::cStr() const // C-string
{
	return data;
}

size_t String::length() const // String length
{
	return size;
}

String& String::operator=(const String& other) // Assignment operator with copying
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

String& String::operator=(String&& other) throw() // Assignment operator with moving
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

String& String::operator=(const char* cStr) // Assignment operator with copying (C-style)
{
	delete[] data;
	size = strlen(cStr);
	data = new char[size + 1];
	std::copy(cStr, cStr + size, data);
	data[size] = '\0';
	return *this;
}

String& String::operator+=(const String& other) // Increment operator
{
	char* newData = new char[size + other.size + 1];
	std::copy(data, data + size, newData);
	std::copy(other.data, other.data + other.size, newData + size);
	size += other.size;
	delete[] data;
	data = newData;
	data[size] = '\0';
	return *this;
}

String& String::operator+=(const char* cStr) // Increment operator (C-style)
{
	size_t strSize = strlen(cStr);
	char* newData = new char[size + strSize + 1];
	std::copy(data, data + size, newData);
	std::copy(cStr, cStr + strSize, newData + size);
	size += strSize;
	delete[] data;
	data = newData;
	data[size] = '\0';
	return *this;
}

String operator+(const String& lvalue, const String& rvalue) // Addition operator
{
	return String(lvalue) += rvalue;
}

String operator+(const String& lvalue, const char* rvalue) // Addition operator (C-style)
{
	return String(lvalue) += String(rvalue);
}

std::ostream& operator<<(std::ostream& os, const String& str) // Shift operator
{
	os << str.data;
	return os;
}

char String::operator[](unsigned index) const // Indexing operator
{
	return data[index];
}

bool String::operator<(const String& other) const // Less-than comparison
{
	return std::lexicographical_compare(data, data + size,
		other.data, other.data + other.size,
		[](char c1, char c2) { return std::tolower(c1) < std::tolower(c2); });
}

bool String::operator>(const String& other) const // Greater-than comparison
{
	return other < *this;
}
