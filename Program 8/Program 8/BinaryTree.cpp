/*********************************************************************************
 *     Title:   BinaryTree.cpp                                                   *
 *     Author:  Maddison Davenport                                               *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is the implementation file for the BinaryTree class, which  *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#include <iostream>
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree()
{
	root = NULL;
}

BinaryTree::~BinaryTree()
{
	destroySubTree(root);	
}

void BinaryTree::destroySubTree(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
		{
			destroySubTree(nodePtr->left);
		}
		if (nodePtr->right)
		{
			destroySubTree(nodePtr->right);
		}
		delete nodePtr;
	}
}

void BinaryTree::insertNode(string newName, int newPatty)
{
	TreeNode *newNode = NULL;

	newNode = new TreeNode;
	newNode->valuePatty = newPatty;
	newNode->name = newName;
	newNode->left = newNode->right = NULL;
   
	insert(root, newNode);
}

void BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if(nodePtr == NULL)
	{
		nodePtr = newNode;
	}
	else if(newNode->name < nodePtr->name)
	{
		insert(nodePtr->left, newNode);
	}
	else
	{
		insert(nodePtr->right, newNode);
	}
}

void BinaryTree::remove(string name)
{
	cout << "You are trying to delete " << name << endl;
	deleteNode(name, root);
	cout << "Your removed " << name << endl;
}

void BinaryTree::deleteNode(string nameDelete, TreeNode *&nodePtr)
{
	if (nameDelete < nodePtr->name && nodePtr->left)
	{
		deleteNode(nameDelete, nodePtr->left);
	}
	else if (nameDelete > nodePtr->name && nodePtr->right)
	{
		deleteNode(nameDelete, nodePtr->right);
	}
	else if (nameDelete == nodePtr->name)
	{
		makeDeletion(nodePtr);
	}
	else 
	{
		cout << "I am sorry.  That customer can not be found in the Krusty Krab.\n";
		return;
	}
}

void BinaryTree::makeDeletion(TreeNode *&nodePtr)
{
	TreeNode *tempNodePtr = NULL;

	if (nodePtr == NULL)
	{
		cout << "Cannot delete empty node.\n";
	}
	else if (nodePtr->right == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; 
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; 
		delete tempNodePtr;
	}
	else
	{
		tempNodePtr = nodePtr->right;
		while (tempNodePtr->left)
		{
			tempNodePtr = tempNodePtr->left;
		}
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}	
}

void BinaryTree::displayInOrder(TreeNode *nodePtr)
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		cout << nodePtr->name << endl;
		displayInOrder(nodePtr->right);
	}
}

void BinaryTree::displayInOrder()
{
	displayInOrder(root);
}

int BinaryTree::searchNode(string nameSearch)
{
	TreeNode *tempNodePtr = root;
	
	while(tempNodePtr)
	{
		if (nameSearch == tempNodePtr->name)
		{
			return tempNodePtr->valuePatty;
		}
		else if (nameSearch < tempNodePtr->name)
		{
			tempNodePtr = tempNodePtr->left;
		}
		else if (nameSearch > tempNodePtr->name)
		{
			tempNodePtr = tempNodePtr->right;
		}
		else
		{
			cout << "That customer is not at the Krusty Krab." << endl;
		}
	}
	return -1;
}

void BinaryTree::getLeastNumPatties(string &leastName, int &leastPatties)
{
	leastPatties = root->valuePatty;
	leastName = root->name;
	
	getLeast(root, leastPatties, leastName);
}

void BinaryTree::getLeast(TreeNode *nodePtr, int &leastPatties, string &leastName)
{
	if (nodePtr)
	{
		getLeast(nodePtr->left, leastPatties, leastName);
		
		if (nodePtr->valuePatty < leastPatties)
		{
			leastPatties = nodePtr->valuePatty;
			leastName = nodePtr->name;
		}
		
		getLeast(nodePtr->right, leastPatties, leastName);
	}
}

void BinaryTree::getMostPatties(string &mostName, int &mostPatties)
{
	mostPatties = root->valuePatty;
	mostName = root->name;
	
	getMost(root, mostPatties, mostName);
}

void BinaryTree::getMost(TreeNode *nodePtr, int &mostPatties, string &mostName)
{
	if (nodePtr)
	{
		getMost(nodePtr->left, mostPatties, mostName);
		
		if (nodePtr->valuePatty > mostPatties)
		{
			mostPatties = nodePtr->valuePatty;
			mostName = nodePtr->name;
		}
		
		getMost(nodePtr->right, mostPatties, mostName);
	}
}

void BinaryTree::getTotal(TreeNode *nodePtr, int& total)
{
	if(nodePtr)
	{
		getTotal(nodePtr->left, total);
		total = total + nodePtr->valuePatty;
		getTotal(nodePtr->right, total);
	}
}

int BinaryTree::getTotalNumPatties()
{
	int total = 0;
	
	getTotal(root, total);
	
	return total;
}

