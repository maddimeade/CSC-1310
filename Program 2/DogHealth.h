/*
	Title:  DogHealth.h
	Author:  Maddison Davenport
	Date:  2/8/2018
	Purpose: Header for DogHealth.cpp
*/

#ifndef DOGHEALTH_H
#define DOGHEALTH_H

#include <iostream>
using namespace std;


class DogHealth
{
	private:
		string dogName; //string - dogs name
		int dogAge; // int - dogs age
		float dogWeight[12]; //array holding dogs weight each month
		int dogHeartRate[12]; //array holding dogs heart rate each month
	
	public:
/* 
	Function Name: DogHealth (constructor)
	Purpose:  ask the user for the name, age, and all the data for the two arrays and enter in the information in to the attributes
	Parameters: name string, age int, weight float, and heart rate int
*/
		DogHealth();
/* 
	Function Name: printDogHealth
	Purpose: print out all the information in the attributes
*/
		void printDogHealth();
/* 
	Function Name: printWeightStatistics
	Purpose: create a dynamically allocated ArrayHelper then print months that the dog had the highest weight and the weight amount, the lowest weight and the weight amount and the average weight of all the months
*/
		void printWeightStatistics();
/* 
	Function Name: printHeartRateStatistics
	Purpose: create a dynamically allocated ArrayHelper object then print months that the dog had the highest resting heart rate and the resting heart rate amount, the lowest resting heart rate and the resting heart rate amount, and the average resting heart rate of all the months
*/
		void printHeartRateStatistics();
};

#endif