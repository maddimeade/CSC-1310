/*
	Title: Zoo.cpp
	Author:  Maddison Davenport
	Date:  2/12/2018
	Purpose:
*/

#include "LinkedList.h"
#include "Creature.h"
#include <iostream>
using namespace std;

/*
	Function name:  enterMagicalCreature
	Parameters:  	address of the creature list
	Purpose:  		allows user to add creatures to the creature list		
*/
void enterMagicalCreature(LinkedList<Creature>*);

/*
	Function name:  enterMagicalCreaturesFromFile
	Parameters:  	address of the creature list
	Purpose:  		allows user to add creatures to the creature list from a file
*/
void enterMagicalCreaturesFromFile(LinkedList<Creature>*);

/*
	Function name:  deleteCreature
	Parameters:  	address of the creature list
	Purpose:  		deletes a creature
*/
void deleteCreature(LinkedList<Creature>*);

/*
	Function name:  Movie (overloaded constructor)
	Parameters:  	address of the creature list
	Purpose:  		prints the creatures and details
*/ 
	
void printCreatures(LinkedList<Creature>*);

/*
	Function name:  Movie (overloaded constructor)
	Parameters:  	creature list
	Purpose:  		saves all the current creatures to a user chosen file
*/
void saveCreaturesToFile(LinkedList<Creature>*);


int main() 
{
	LinkedList<Creature> creatureList;

	int usrChoice;
	int numChoice;
	int userAnswer;
	
	do {
	
		cout << "\n\nWhat would you like to do?\n";
		cout << "\t1. Enter Magical Creature\n";
		cout << "\t2. Delete a Magical Creature\n";
		cout << "\t3. List/Print Creatures\n";
		cout << "\t4. End Program\n";
		cout << "\tEnter 1, 2, 3, or 4.\n";
		cout << "CHOICE: ";	
		cin >> usrChoice;
		cout << endl << endl;
		
		while (usrChoice < 1 || usrChoice > 4) {
			cout << "Your choice was invalid. Choose a number 1 through 4.\n";
			cout << "CHOICE: ";
			cin >> usrChoice;
			cout << endl << endl;	
		}
		
		switch(usrChoice) 
		{
			
			case 1:
			
				cout << "Do you want to enter the creature(s)";
				cout << "\n\t1. Manually?\n";
				cout << "\t2. From a file?\n";
				cout << "ENTER 1 or 2: ";
				cin >> numChoice;
				cout << endl << endl;
				
				while (numChoice < 1 || numChoice > 2) 
				{
					cout << "Your choice was invalid.\nENTER 1 or 2: ";
					cin >> numChoice;
				}
				
				if (numChoice == 1) 
				{
					enterMagicalCreature(&creatureList);
				}
				
				if (numChoice == 2) 
				{
					enterMagicalCreaturesFromFile(&creatureList);	
				}
			
				break;
			
			case 2:
			
				deleteCreature(&creatureList);
			
				break;
			
			case 3:
			
				printCreatures(&creatureList);
			
				break;
	}
	
	
	} while (usrChoice != 4);
	
	cout << "Would you like to save the file?" << endl;
	cout << "1. yes\n2. no\n";
	cin >> userAnswer;
	
	if (userAnswer = 1) 
	{
		saveCreaturesToFile(&creatureList);
		cout << "\nGoodbye!";
	}
	else 
	{
		cout << "\nGoodbye!";
	}
	
	
	return 0;
}

void enterMagicalCreature(LinkedList<Creature>* creatureList)
{
	char userChoice;
	
	do {
		string name;
		string description;
		char danger;
		float cost;
		
		Creature newCreature;
		
		cout << "NAME: ";
		cin.ignore();
		getline(cin, name);
		newCreature.setName(name);
		
		cout << "\n\nDESCRIPTION: ";
		getline(cin, description);
		newCreature.setDescription(description);
		
		cout << "\n\nIS IT A DANGEROUS CREATURE? (y or n): ";
		cin >> danger; 
			
		while (danger != 'n' && danger != 'y') {
			cout << "\nIncorrect response. Choose y or n ";
			cin >> danger;
			cout << endl;
		}
			
		if (danger == 'n') {
			newCreature.setDangerous(false);
		}
			
		if (danger == 'y') {
			newCreature.setDangerous(true);
		}
			
		cout << "\n\nCOST PER MONTH TO CARE FOR CREATURE: ";
		cin  >> cost;
		newCreature.setCost(cost);
			
		cout << "\nThe " << newCreature.getName() << " has been added to the zoo.\n\n";
			
		cout << "Want to add more creatures? (y or n): ";

		cin >> userChoice;
		
		cout << endl << endl;
		
		creatureList->appendNode(newCreature);
			
	} while (userChoice == 'y');
}
	
void enterMagicalCreaturesFromFile(LinkedList<Creature>* creatureList)
{
	int numNewCreature = 0;
	Creature newCreature;
	ifstream inFile;
	string filename;
	string text;
	int danger;
	float cost;
		
	cout << "What is the name of the file you want to read from?\n";
	cout << "FILENAME: ";
	cin.ignore();
	getline(cin,filename);
		
	inFile.open(filename.c_str());
	
	if(inFile.good())
	{ 
		getline(inFile, text);
		
		while(!inFile.eof())
		{
			newCreature.setName(text);
			
			getline(inFile, text);
			
			newCreature.setDescription(text);
			
			inFile >> danger;
			
			if (danger == 1)
			{
				newCreature.setDangerous(true);
			}
			
			else 
			{
				newCreature.setDangerous(false);
			}
			
			inFile >> cost;
			
			newCreature.setCost(cost);	
				
			creatureList->appendNode(newCreature);
			
			numNewCreature++;
			
			inFile.ignore();
			getline(inFile, text);
			
		}
	}	
	else
	{
	cout << "\n\nSorry, I was unable to open the file.\n";
	}
	
	cout << endl << endl << numNewCreature << " creatures were added to the zoo from " << filename << "." << endl << endl;
	
	inFile.close();
}
	
void deleteCreature(LinkedList<Creature>* creatureList)
{
	Creature holdCreature;
	
	int num = creatureList->getLength();
	int creatureNum = 0;
	int i = 1;
	
	if (num > 0)
	{
		cout << "The following is a list of all the creatures you take care of:\n";
			
		for (i = 1; i <= num; i++)
		{
			holdCreature = creatureList->getNodeValue(i);
			cout << i << ") " << holdCreature.getName() << endl; 
		}
			
		cout << "\n\nWhat creature do you wish to remove?\n";
		cout << "CREATURE NUMBER: ";
			
		cin >> creatureNum;
		
		while (creatureNum > num || creatureNum < 0) 
		{
			cout << "\nIncorrect option, which creature do you wish to remove?\n";
			cout << "CREATURE NUMBER: ";
			
			cin >> creatureNum;
		}
			
		i = creatureNum;
			
		creatureList->deleteNode(i);
			
		cout << "\n\nYou have removed the creature.";
	}
	else
	{
		cout << endl << "YOU HAVE NO CREATURES IN YOUR ZOO!" << endl << endl;
	}
}
	
void printCreatures(LinkedList<Creature>* creatureList) 
{
	int num = creatureList->getLength();
	Creature holdData;	
		
	if (num < 1) 
	{
		cout << "There are no creatures at your zoo!";
	}
	else
	{
		for (int i = 1; i <= num; i++) 
		{
			cout << "-----------------------------------------------" << endl;
			cout << "CREATURE: " << i << endl;
			
			holdData = creatureList->getNodeValue(i);
			holdData.printCreature();
		}
	}
}
void saveCreaturesToFile(LinkedList<Creature>* creatureList)
{
	int num = creatureList->getLength();
	ofstream outFile;
	Creature holdCreature;
	string fileName;
	
	if (num <= 0) 
	{
		cout << "THERE ARE NO CREATURES AT YOUR ZOO!";
	}
	
	else
	{
		cout << "What is your file name?";
		cin.ignore();
		getline(cin, fileName);
		outFile.open(fileName.c_str());
	
		for (int i = 1; i <= num; i++)
		{
			holdCreature = creatureList->getNodeValue(i);
			holdCreature.printCreatureToFile(outFile);
		}
	}
	outFile.close();		
}

