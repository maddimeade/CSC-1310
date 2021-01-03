/*
	Title:  ArrayHelper.h
	Author:  Maddison Davenport
	Date:  2/8/2018
	Purpose: Perform common array functions on any numerical data type
*/

#ifndef ARRAYHELPER_H
#define ARRAYHELPER_H

#include <iostream>
using namespace std;

template <typename name>
class ArrayHelper 
{
	private: 
		name* arrayPtr; //pointer to an array of the template type
		int numElements; //integer containing number of elements in array
		
	public: 
/* 
	Function Name: ArrayHelper (constructor)
	Purpose: Set the number of elements attribute to the number sent to this function and create a dynamically allocated array of the same size and then copy the array elements from the array parameter into the ArrayHelper object’s array
	Parameters: A pointer of type name, and int
*/
		ArrayHelper(name*, int);
/* 
	Function Name: ~ArrayHelper (destructor)
	Purpose: release the dynamically allocated array
*/
		~ArrayHelper();
/* 
	Function Name: getMax
	Purpose: find the largest number in the array
	Returns: int index of the element that contains the largest number
*/
		int getMax();
/* 
	Function Name: getMin
	Purpose: find the smallest number in the array
    Returns: int index of the element that contains the smallest number.
*/
		int getMin();
/* 
	Function Name: getTotal
	Purpose: find the total of all the elements
	Returns: the total
*/
		name getTotal();
/* 
	Function Name: getAvg
	Purpose: find the average of all the elements
	Returns: the average
*/
		float getAvg();
	
};

#include "ArrayHelper.cpp"
#endif
