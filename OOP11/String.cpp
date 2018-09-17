#include <iostream>
#include <cstring>
#include "String.h"
using namespace std;

String::String(const char* ref)
{
	len = strlen(ref) + 1;
	string = new char[len];
	strcpy_s(string, len, ref);
}
String::String()
{
	len = 0;
	string = NULL;
}
String::String(const String& ref)
{
	len = ref.len;
	string = new char[len];
	strcpy_s(string, len, ref.string);
}
String& String::operator= (const String& ref)
{
	if (string != NULL)
		delete[] string;
	len = ref.len;
	string = new char[len];
	strcpy_s(string, len, ref.string);
	return *this;
}
String String::operator+ (const String& ref)
{
	int newLen = len + ref.len - 1;
	char* temp = new char[newLen];
	strcpy_s(temp, len, string);
	strcat_s(temp, newLen, ref.string);
	String newString(temp);
	delete[]temp;
	return newString;
}
String& String::operator+= (const String& ref)
{
	char* temp = new char[len + ref.len - 1];
	strcpy_s(temp, len, string);
	strcat_s(temp, len + ref.len - 1, ref.string);

	if (string != NULL)
		delete[] string;
	string = temp;
	return *this;
}
bool String::operator== (const String& ref)
{
	if (strcmp(string, ref.string))
		return false;
	else
		return true;
}
String::~String()
{
	if (string != NULL)
		delete[] string;
}


ostream& operator<< (ostream& os, const String& ref)
{
	os << ref.string;
	return os;
}

istream& operator>> (istream& is, String& ref)
{
	char temp[100];
	is >> temp;
	ref.len = strlen(temp) + 1;
	ref.string = new char[ref.len];
	strcpy_s(ref.string, ref.len, temp);
	return is;
}