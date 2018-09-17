#include <cstdlib>
#include <iostream>
using namespace std;
#include "ArrayTemplate.h"

template <typename T>
BoundCheckTemplateArray<T>::BoundCheckTemplateArray(int len) : arrlen(len)
{
	arr = new T[len];
}

template <typename T>
T& BoundCheckTemplateArray<T>::operator[] (int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "¹üÀ§ ¹þ¾î³²" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
T BoundCheckTemplateArray<T>::operator[] (int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "¹üÀ§ ¹þ¾î³²" << endl;
		exit(1);
	}
	return arr[idx];
}

template <typename T>
int BoundCheckTemplateArray<T>::GetArrLen() const { return arrlen; }

template <typename T>
BoundCheckTemplateArray<T>::~BoundCheckTemplateArray() { delete[]arr; }