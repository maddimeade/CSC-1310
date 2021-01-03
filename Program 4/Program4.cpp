/*
	Title: Program4.cpp
	Author:  Maddison Davenport
	Date:  2/12/2018
	Purpose:
*/

#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

double calculateExpression(string expression);
bool isLowerPriority(char a, char b);

int main()
{
	string infix;
	string tempString;
	string postfixString;
	char token;
	char usrChoice;
	char token2;
	Queue<char> infixQueue;
	Queue<char> postfixQueue;
	Stack<char> operatorStack;
	
	
	cout << "Infix to Postfix Converter\n\n";
	
	do {
		
		cout << "Enter your infix expression: ";
		getline(cin, infix);
		
		//takes space out of string
		for(int i = 0; i < infix.size(); i++)
		{
			if(infix.at(i) == ' ')
			{
				tempString = infix.substr((i + 1), (infix.size()- i));
				infix = infix.substr(0, i);
				
				infix = infix.replace(i, i, tempString);
			}
		}
		
		cout << "Infix Expression: ";
		
		//prints infix with spaces
		for(int i = 0; i < infix.size(); i++)
		{
			cout << infix.at(i) << " ";
		}
		
		//puts characters in infix queue
		for(int i = 0; i < infix.size(); i++)
		{
			infixQueue.push_back(infix.at(i));
		}
		
		//making postfix queue
		while(!infixQueue.isEmpty())
		{
			token = infixQueue.pop_front();
			
			if(token == '(') 
			{
				operatorStack.push(token);
			}
			else if(token == ')')
			{
				while(operatorStack.peek() != '(')
				{
					postfixQueue.push_back(operatorStack.pop());
				}
				token2 = operatorStack.pop();
			}
			else if(token == '-' || token == '+' || token == '/' || token == '*')
			{
				while(!operatorStack.isEmpty() && isLowerPriority(token, operatorStack.peek()))
				{
					postfixQueue.push_back(operatorStack.pop());
				}
				operatorStack.push(token);
			}
			else
			{
				postfixQueue.push_back(token);
			}
		}
		while(!operatorStack.isEmpty())
		{
			postfixQueue.push_back(operatorStack.pop());
		}
		
		cout << endl;
		cout << "Postfix Expression: ";
		postfixQueue.Display();
		cout << endl;
		cout << "Result of the Expression: ";
		
		while(!postfixQueue.isEmpty()) 
		{
			postfixString = postfixString + postfixQueue.pop_front();
		}
		
		cout << calculateExpression(postfixString);
		cout << endl;
		cout << "Would you like to run the program again? (Y/N) ";
		cin >> usrChoice;
		cout << endl;
		
		if (usrChoice != 'n' && usrChoice != 'N' && usrChoice != 'y' && usrChoice != 'Y') 
		{
			cout << "Invalid choice, choose Y/N";
			cin >> usrChoice;
			cout << endl;
		}	
		
	cin.ignore();
	
	}while (usrChoice == 'y' || usrChoice == 'Y');
	
	cout << "Goodbye!";

	return 0;
}

double calculateExpression(string expression) 
{
	Stack<double> numbersStack;
	char toConvert;
	double converted;
	double pop1;
	double pop2;
	double result;

	for(int i = 0; i < expression.size(); i++)
	{
		if(isdigit(expression.at(i)))
		{
			toConvert = expression.at(i);
		    converted = static_cast<double>(toConvert - '0');
			numbersStack.push(converted);
		}
		else
		{
			pop1 = numbersStack.pop();
			pop2 = numbersStack.pop();
			
			if(expression.at(i) == '+') 
			{
				result = pop1 + pop2;
				numbersStack.push(result);
			}
			if(expression.at(i) == '-')
			{
				result = pop2 - pop1;
				numbersStack.push(result);
			}
			if(expression.at(i) == '*')
			{
				result = pop1 * pop2;
				numbersStack.push(result);
			}
			if(expression.at(i) == '/')
			{
				result = pop2 / pop1;
				numbersStack.push(result);
			}
		}
	}
	return result;
}

bool isLowerPriority(char a, char b)
{
	int aPriority;
	int bPriority;
	
	if(a == '(')
	{
		aPriority = 0;
	}
	if(b == '(')
	{
		bPriority = 0;
	}
	if(a == ')')
	{
		aPriority = 3;
	}
	if(b == ')')
	{
		bPriority = 3;
	}
	if(a == '*' || a == '/')
	{
		aPriority = 2;
	}
	if(b == '*' || b == '/')
	{
		bPriority = 2;
	}
	if(a == '+' || a == '-')
	{
		aPriority = 1;
	}
	if(b == '+' || b == '-')
	{
		bPriority = 1;
	}
	
	if(aPriority <= bPriority) 
	{
		return true;
	}
	else
	{ 
		return false;
	}
}