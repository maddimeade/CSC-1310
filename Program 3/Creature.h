/*
	Title: Creature.h
	Author:  Maddison Davenport
	Date:  2/12/2018
	Purpose:
*/

#ifndef CREATURE_H
#define CREATURE_H

#include <iostream>
#include <fstream>
using namespace std;


class Creature 
{
	private:
		
		string creatureName;
		string creatureDescription;
		float costPerMonth;
		bool dangerous;
	
	public:
	
/*
	Function name:  Creature constructor
	Parameters:  	none
	Returns: 		none
	Purpose:  		default constructor
*/
		Creature();
		
/*
	Function name:  Creature constructor
	Parameters:  	a string name of creature, string description of creature, bool whether creature is dangerous, and float monthly cost 
	Returns: 		none
	Purpose:  		initializes creatures attributes
*/
		Creature(string name, string description, bool danger, float cost);
		
/*
	Function name:  getName
	Parameters:  	none
	Returns: 		string of creatures name
	Purpose:  		to return the creatures name
*/
		string getName();
		
/*
	Function name:  getDescription
	Parameters:  	none
	Returns: 		string of creatures description
	Purpose:  		to return the creatures description
*/
		string getDescription();
		
/*
	Function name:  getDangerous
	Parameters:  	none
	Returns: 		boolean variable on whether creature is dangerous
	Purpose:  		returns whether creature is dangerous or not
*/
		bool getDangerous();
		
/*
	Function name:  getCost
	Parameters:  	none
	Returns: 		float of monthly cost
	Purpose:  		returns monthly cost of creature
*/
		float getCost();
		
/*
	Function name:  setName
	Parameters:  	string of creatures name
	Returns: 		nothing (void)
	Purpose:  		let user set name
*/
		void setName(string name);
		
/*
	Function name:  setDescription
	Parameters:  	string of creatures description
	Returns: 		nothing (void)
	Purpose:  		let user set description
*/
		void setDescription(string description);
		
/*
	Function name:  setDangerous
	Parameters:  	bool for whether creature is dangerous
	Returns: 		nothing (void)
	Purpose:  		lets user set danger status
*/
		void setDangerous(bool danger);
	
/*
	Function name:  setCost
	Parameters:  	float of creature monthly cost
	Returns: 		nothing (void)
	Purpose:  		lets user set monthly cost of creature
*/
		void setCost(float cost);
		
/*
	Function name:  printCreature
	Parameters:  	
	Returns: 		nothing (void)
	Purpose:  		prints details for individual creature
*/
		void printCreature();
		
/*
	Function name:  printCreaturesToFile 
	Parameters:  	
	Returns: 		nothing (void)
	Purpose:  		print details for creatures to a file
*/
		void printCreatureToFile(ofstream &outFile);
};

#endif