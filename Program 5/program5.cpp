#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nThe result is: " << sumOfNumbers(num);
				//print out the result of the sumOfNumbers function here
				
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				if(isMember(myArray, num, ARRAY_SIZE) == true)
				{
					cout << "Yes. " << num << " is in the array.\n\n";
				}
				else
				{
					cout << "No. " << num << " is not in the array.\n\n";
				}
				//print if the value that the user entered is in the array or not here
				
				
				break;
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				stringReverser(userString, userString.length());
				
				//call string reverser function here
				
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces from string
				userStrWithoutSpaces = userString;
				for(int x=0; x<userStrWithoutSpaces.size(); x++)
				{
					if(userStrWithoutSpaces[x] == ' ') 
						userStrWithoutSpaces.erase(x, 1);
				}
				
				if(isPalindrome(userStrWithoutSpaces) == true)
				{
					cout << endl << userString << " is a palindrome.";
				}
				if(isPalindrome(userStrWithoutSpaces) == false)
				{
					cout << endl << userString << " is NOT a palindrome.";
				}
				//print out whether the user's string is a palindrome or not here.
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				cout << multiply(num1, num2);
				//print out the value returned from the multiply function here
				
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}

int sumOfNumbers(int number)
{
	while(number > 0)
	{
		return sumOfNumbers(number - 1) + number;
	}
}

bool isMember(int* array, int value, int size)
{
	if(size > 0)
	{
		if(value == array[size - 1]) 
		{
			return true;
		}
		else
		{
			return isMember(array, value, size - 1);
		}		
	}
	else
	{
		return false;
	}	
}

void stringReverser(string usrString, int size)
{
	if(size > 0)
	{
		cout << usrString.at(size - 1);
		stringReverser(usrString, --size);
	}
}

bool isPalindrome(string usrString)
{	
	if(usrString.length() > 1)
	{
		if(usrString[0] == usrString[usrString.length() - 1])
		{
			usrString = usrString.substr(1, usrString.length() - 2);
			return isPalindrome(usrString);
		}	
		else
		{
			return false;
		}
	}
	if(usrString.length() < 2)
	{ 
	return true;
	}
}

int multiply(int number1, int number2)
{
	while(number2 > 0)
	{
		return number1 + multiply(number1, number2 - 1);
	}
}


