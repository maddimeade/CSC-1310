/*
	Title: Stack.h
	Author:  Maddison Davenport
	Date:  2/22/2018
	Purpose:
*/

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <typename S>
class Stack
{
	private:
	
		struct ListNode
		{
			S value;
			struct ListNode *below;
		};
		ListNode *head;
	
	public:
	
		Stack();
		~Stack();
		void push(S x);
		S pop();
		S peek();
		bool isEmpty();
};

template <typename S>
Stack<S>::Stack()
{
	head = NULL;
}

template <typename S>
Stack<S>::~Stack()
{
	ListNode *nodePtr;
	ListNode *nextNode;
	
	nodePtr = head;
	
	while(nodePtr)
	{
		nextNode = nodePtr->below;
		
		delete nodePtr;
		
		nodePtr = nextNode;
	}
}

template <typename S>
void Stack<S>::push(S x)
{
	ListNode *newNode;
	
	newNode = new ListNode;
	
	newNode->value = x;
	if(!head)
	{
		newNode->below = NULL;
	}
	else 
	{
		newNode->below = head;
	}
	head = newNode;
}

template <typename S>
S Stack<S>::pop()
{
	ListNode *nodePtr;
	S temp;
	
	nodePtr = head;
	if(head->below != NULL)
	{
		head = head->below;
	}
	else
	{
		head = NULL;
	}
	temp = nodePtr->value;
	delete nodePtr;
	
	return temp;
}

template <typename S>
S Stack<S>::peek()
{
	return head->value;
}

template <typename S>
bool Stack<S>::isEmpty()
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

#endif