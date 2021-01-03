/*
	Title:  ArrayHelper.cpp
	Author:  Maddison Davenport
	Date:  2/8/2018
	Purpose: Header for ArrayHelper.cpp 
*/

#include "ArrayHelper.h"

template <typename name>
ArrayHelper<name>::ArrayHelper(name* ptr, int elements)
{
	numElements = elements;
	
	arrayPtr = new name[numElements];
	
	for (int i = 0; i < numElements; i++)
	{
		arrayPtr[i] = ptr[i];
	}	
}

template <typename name>
ArrayHelper<name>::~ArrayHelper()
{
	delete arrayPtr;
}

template <typename name>
int ArrayHelper<name>::getMax()
{
	int element = 0;
	
	for (int i = 0; i < numElements; i++)
	{
		if (arrayPtr[i] > arrayPtr[element])
		{
			element = i;
		}
	}	
	return element;
}

template <typename name>
int ArrayHelper<name>::getMin()
{
	int element = 0;
	
	for (int i = 0; i < numElements; i++)
	{
		if (arrayPtr[i] < arrayPtr[element])
		{
			element = i;
		}
	}
	return element;
}

template <typename name>
name ArrayHelper<name>::getTotal()
{
	name total = 0;
	for (int i = 0; i < numElements; i++)
	{
		total = total + arrayPtr[i];
	}
	return total;
}

template <typename name>
float ArrayHelper<name>::getAvg()
{
	name total = 0;
	float avg = 0;
	
	total = getTotal();
	avg = total / 12.0;
	
	return avg;
}