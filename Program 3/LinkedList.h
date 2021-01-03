/*
	Title: LinkedList.h
	Author:  Maddison Davenport
	Date:  2/12/2018
	Purpose:
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <fstream>
using namespace std;

template <typename name>
class LinkedList 
{
	private:
	
		struct ListNode
		{
			name value;
			struct ListNode* next;
		};
		ListNode* head;
		ListNode* tail;
		int numNodes;
		
	public:
	
/*
	Function name:  LinkedList constructor
	Parameters:  	none
	Returns: 		none
	Purpose:  		default constructor
*/
		LinkedList();
		
/*
	Function name:  LinkedList destructor
	Parameters:  	none
	Returns: 		none
	Purpose:  		destructor for linked list
*/
		~LinkedList();
		
/*
	Function name:  getLength
	Parameters:  	none
	Returns: 		int number of nodes
	Purpose:  		gets length of list
*/
		int getLength();
		
/*
	Function name:  getNodeValue
	Parameters:  	the position
	Returns: 		object inside the node at that position
	Purpose:  		gets value of a node
*/
		name getNodeValue(int position);
		
/*
	Function name:  appendNode
	Parameters:  	value of type name
	Returns: 		none
	Purpose:  		creates a new node at the end of the list with the sent object inside of it and increments the number of nodes
*/
		void appendNode(name value);
		
/*
	Function name:  deleteNode
	Parameters:  	the position
	Returns: 		none
	Purpose:  		deletes a node
*/
		void deleteNode(int position);
};

template <typename name>		
LinkedList<name>::LinkedList()
{
	head = NULL;
	tail = NULL;
	numNodes = 0;
}

template <typename name>
LinkedList<name>::~LinkedList()
{
	ListNode *nodePtr;   
	ListNode *nextNode;  

	nodePtr = head;

	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;

		delete nodePtr;

		nodePtr = nextNode;
	}
}

template <typename name>
int LinkedList<name>::getLength()
{
	return numNodes;
}

template <typename name>
name LinkedList<name>::getNodeValue(int position)
{
	ListNode *nodePtr;
	
	if(position == 1)
		return head->value;

	nodePtr = head;
	int currentPosition = 1;
		
	while(currentPosition <= position)
	{
		if(currentPosition == position)
			return nodePtr->value;
			
		currentPosition++;
		nodePtr = nodePtr->next;				
	}	
}

template <typename name>
void LinkedList<name>::appendNode(name num)
{
	ListNode *newNode;

	newNode = new ListNode;
	newNode->value = num;
	newNode->next = NULL;

	if (!head ) 
	{
		head = newNode;
		tail = newNode;
	}
	else  
	{
		tail->next = newNode;
		tail = newNode;
	}
	numNodes++;
}

template <typename name>
void LinkedList<name>::deleteNode(int position)
{
	ListNode *nodePtr;
	ListNode *previousNode;
	int counter = 1;

	if (!head)
		return;

	if (position == 1)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
		
		numNodes--;
	}
	else
	{
		nodePtr = head;

		while (counter < position)
		{  
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			counter++;
		}

		if (nodePtr)
		{
			if(nodePtr == tail)
			{
				tail = previousNode;
			}
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}	
		numNodes--;
	}	
}

#endif
