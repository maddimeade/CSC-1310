/*
	Title:  DogHealth.cpp
	Author:  Maddison Davenport
	Date:  2/8/2018
	Purpose: Allow a user to enter in information about a dog and then get statistics based on that information.
*/

#include "DogHealth.h"
#include "ArrayHelper.h"

DogHealth::DogHealth()
{	     
	cout << "\n\nWhat is the dog's name?";
	
	getline(cin, dogName);
	
	cout << "\nWhat is the dogs age?";
	
	cin >> dogAge;
	
	cout << "\n\n\nPlease enter the dog's weight (LBS) & resting heart rate (BPM) for each month in 2017.\n\n";
	
	for (int i = 0; i < 12; i++)
	{
		cout << "MONTH " << i + 1 << " WEIGHT: ";
		
		cin >> dogWeight[i];
		
		cout << "\nMONTH " << i + 1 << " RESTING HEART RATE: ";
		
		cin >> dogHeartRate[i];
		
		cout << endl << endl;
	}	
	
	cout << "\nThank you! " << dogName << "'s data has been saved\n\n";
}

void DogHealth::printDogHealth()
{
	cout << "\n\tNAME:\t\t" << dogName << endl << endl;
	cout << "\tAGE:\t\t" << dogAge << endl << endl;
	cout << "\tWEIGHT PER MONTH:" << endl << endl;
	
	for (int i = 0; i < 12; i++) {
		cout << "\t\tMONTH " << i + 1 << ": " << dogWeight[i] << endl;
	}
	
	cout << endl << endl;
	cout << "\tHEART RATE PER MONTH:" << endl << endl;
	
	for (int i = 0; i < 12; i++) {
		cout << "\t\tMONTH " << i + 1 << ": " << dogHeartRate[i] << endl;
	}
	
	cout << endl << endl;
}


void DogHealth::printWeightStatistics()
{
	ArrayHelper<float>* weightStats = new ArrayHelper<float>(dogWeight, 12);
	
	cout << "Weight Statistics\n" << "------------------------------";
	
	int maxMonth = weightStats->getMax();
	int minMonth = weightStats->getMin();
	float avg = weightStats->getAvg();
	
	cout << endl << dogName << " had the highest weight in month " << maxMonth + 1 << " at " << dogWeight[maxMonth] << " pounds.\n\n";
	cout << dogName << " had the lowest weight in month " << minMonth + 1 << " at " << dogWeight[minMonth] << " pounds.\n\n";
	cout << dogName << "'s average weight over one year was " << avg << endl << endl;
}

void DogHealth::printHeartRateStatistics()
{
	ArrayHelper<int>* heartRateStats = new ArrayHelper<int>(dogHeartRate, 12);
	
	cout << "Heart Rate Statistics\n" << "------------------------------";
	
	int maxMonth = heartRateStats->getMax();
	int minMonth = heartRateStats->getMin();
	float avg = heartRateStats->getAvg();
	
	cout << endl << dogName << " had the highest resting heart rate in month " << maxMonth + 1 << " at " << dogHeartRate[maxMonth] << " beats per minute.\n\n";
	cout << dogName << " had the lowest resting heart rate in month " << minMonth + 1 << " at " << dogHeartRate[minMonth] << " beats per minute.\n\n";
	cout << dogName << "'s average resting heart rate over one year was " << avg << endl << endl;
}
