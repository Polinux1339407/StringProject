#pragma once

#include<ostream>

class String
{
public:
	String(); // Default constructor
	String(const char* c_str); // Constructor for a sequence of characters
	String(const String& other); // Copy constructor
	String(String&& other) throw(); // Move constructor
	~String(); // Destructor
	char* c_str() const; // C-string
	size_t length() const; // String length
	String& operator=(const String& other); // Assignment operator with copying
	String& operator=(String&& other) throw(); // Assignment operator with moving
	String& operator=(const char* c_str); // Assignment operator with copying (C-style)
	String& operator+=(const String& other); // Increment operator
	String& operator+=(const char* c_str); // Increment operator (C-style)
	friend String operator+(const String& lvalue, const String& rvalue); // Addition operator
	friend String operator+(const String& lvalue, const char* rvalue); // Addition operator (C-style)
	friend std::ostream& operator<<(std::ostream& os, const String& str); // Shift operator
	char operator[](unsigned index) const; // Indexing operator
	bool operator<(const String& other) const; // Less-than comparison
	bool operator>(const String& other) const; // Greater-than comparison

private:
	char* data;
	size_t size;
};

