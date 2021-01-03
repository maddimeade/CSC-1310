/*
	Title: Queue.h
	Author:  Maddison Davenport
	Date:  2/12/2018
	Purpose:
*/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename Q>
class Queue
{
	private:
	
		struct ListNode
		{
			Q value;
			struct ListNode *next;
		};
		ListNode *head;
		ListNode *tail;
		int numItems;
	
	public:
	
		Queue();
		~Queue();
		void push_back(Q x);
		Q pop_front();
		bool isEmpty();
		void Display();
};

template <typename Q>
Queue<Q>::Queue()
{
	head = NULL;
	tail = NULL;
	numItems = 0;
}

template <typename Q>
Queue<Q>::~Queue()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	
	nodePtr = head;
	
	while(nodePtr)
	{
		nextNode = nodePtr->next;
		
		delete nodePtr;
		
		nodePtr = nextNode;
	}	
}

template <typename Q>
void Queue<Q>::push_back(Q x)
{
	ListNode *newNode = NULL;
	
	newNode = new ListNode;
	
	newNode->value = x;
	newNode->next = NULL;
	
	if(isEmpty()) 
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	numItems++;
}

template <typename Q>
Q Queue<Q>::pop_front()
{
	ListNode *temp = NULL;
	Q item;
	
	if(isEmpty())
	{
		cout << "The queue is empty.\n";
	}
	else
	{
		item = head->value;
		
		temp = head;
		head = head->next;
		delete temp;
		
		numItems--;
	}
	return item;
}

template <typename Q>
bool Queue<Q>::isEmpty()
{
	if(!head)
	{
		return true;
	}
	else 
	{
		return false;
	}
	
}

template <typename Q>
void Queue<Q>::Display()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	
	nodePtr = head;
	
	do
	{
		nextNode = nodePtr->next;
		
		cout << nodePtr->value << " ";
		
		nodePtr = nextNode;
		
	}while(nodePtr != tail->next);	
}

#endif