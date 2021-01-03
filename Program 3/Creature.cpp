/*
	Title: Creature.cpp
	Author:  Maddison Davenport
	Date:  2/12/2018
	Purpose:
*/

#include "Creature.h" 

//initializing everything
Creature::Creature()
{
	creatureName = "";
	creatureDescription = "";
	dangerous = false;
	costPerMonth = 0.0;
}
Creature::Creature(string name, string description, bool danger, float cost)
{
	creatureName  = name;
	creatureDescription = description;
	dangerous = danger;
	costPerMonth = cost;
}
string Creature::getName()
{
	return creatureName;
}
string Creature::getDescription()
{
	return creatureDescription;
}
bool Creature::getDangerous()
{
	return dangerous;
}
float Creature::getCost()
{
	return costPerMonth;
}
void Creature::setName(string name)
{
	creatureName = name;
}
void Creature::setDescription(string description)
{
	creatureDescription = description;
}
void Creature::setDangerous(bool danger)
{
	dangerous = danger;
}
void Creature::setCost(float cost)
{
	costPerMonth = cost;
}
void Creature::printCreature()
{
	cout << "Name: " << creatureName << endl;
	cout << "Description: \n\t" << creatureDescription << endl;
	cout << "Dangerous? ";
	
	if (dangerous == false) {
		cout << "no\n";
	}
	
	if (dangerous == true) {
		cout << "yes\n";
	}
	
	cout << "Cost per month to care for creature: $" << costPerMonth << endl << endl;
}
void Creature::printCreatureToFile(ofstream &outFile)
{
	outFile << creatureName << endl;
	outFile << creatureDescription << endl;
	if (dangerous == true) 
	{
		outFile << "1" << endl;
	}
	else
	{
		outFile << "0" << endl;
	}
	outFile << costPerMonth << endl;
}
