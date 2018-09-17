#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
using namespace std;

class String
{
private:
	char* string;
	int len;
public:
	String(const char* ref);
	String();
	String(const String& ref);
	String& operator= (const String& ref);
	String operator+ (const String& ref);
	String& operator+= (const String& ref);
	bool operator== (const String& ref);
	~String();

	friend ostream& operator<< (ostream& os, const String& ref);
	friend istream& operator>> (istream& is, String& ref);
};



#endif // !__STRING_H__

