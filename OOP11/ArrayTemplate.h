#ifndef __ARRAY_TEMPLATE_H__
#define __ARRAY_TEMPLATE_H__
#include <iostream>
using namespace std;

template <typename T>
class BoundCheckTemplateArray
{
private:
	T* arr;
	int arrlen;
	BoundCheckTemplateArray(const  BoundCheckTemplateArray& arr) {}
	BoundCheckTemplateArray& operator= (const  BoundCheckTemplateArray& arr) {}

public:
	BoundCheckTemplateArray(int len = 100);
	T& operator[] (int idx);
	T operator[] (int idx) const;
	int GetArrLen() const;
	~BoundCheckTemplateArray();

};




#endif // !__BOUND_CHECK_TEMPLATE_ARRAY_H__
