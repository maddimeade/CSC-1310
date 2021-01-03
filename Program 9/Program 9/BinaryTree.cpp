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
	root = balance(root);
}

BinaryTree::TreeNode* BinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
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

BinaryTree::TreeNode* BinaryTree::balance(TreeNode *nodePtr)
{
	int bal_factor = diff(nodePtr);
    if (bal_factor > 1)
    {
        if (diff(nodePtr->left) > 0)
            nodePtr = ll_rotation(nodePtr);
        else
            nodePtr = lr_rotation(nodePtr);
    }
    else if (bal_factor < -1)
    {
        if (diff(nodePtr->right) > 0)
            nodePtr = rl_rotation(nodePtr);
        else
            nodePtr = rr_rotation(nodePtr);
    }
    return nodePtr;
}

int BinaryTree::height(TreeNode *nodePtr)
{
	int h = 0;
	if (nodePtr != NULL)
	{
		int l_height = height(nodePtr->left);
		int r_height = height(nodePtr->right);
		int max_height = max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

int BinaryTree::diff(TreeNode *nodePtr)
{
	int l_height = height(nodePtr->left);
    int r_height = height(nodePtr->right);
    int b_factor= l_height - r_height;
    return b_factor;
}

BinaryTree::TreeNode* BinaryTree::rr_rotation(TreeNode *nodePtr)
{
	TreeNode *temp;
    temp = nodePtr->right;
    nodePtr->right = temp->left;
    temp->left = nodePtr;
    return temp;
}

BinaryTree::TreeNode* BinaryTree::ll_rotation(TreeNode *nodePtr)
{
	TreeNode *temp;
    temp = nodePtr->left;
    nodePtr->left = temp->right;
    temp->right = nodePtr;
    return temp;
}

BinaryTree::TreeNode* BinaryTree::lr_rotation(TreeNode *nodePtr)
{
    TreeNode *temp;
    temp = nodePtr->left;
    nodePtr->left = rr_rotation(temp);
    return ll_rotation(nodePtr);
}

BinaryTree::TreeNode* BinaryTree::rl_rotation(TreeNode *nodePtr)
{	
    TreeNode *temp;
    temp = nodePtr->right;
    nodePtr->right = ll_rotation(temp);
    return rr_rotation(nodePtr);
}

void BinaryTree::display(TreeNode *nodePtr, int level)
{
	int i;
    if (nodePtr != NULL)
    {
        display(nodePtr->right, level + 1);
        printf("\n");
        if (nodePtr == root)
        cout<<"Root -> ";
        for (i = 0; i < level && nodePtr != root; i++)
            cout<<"        ";
        cout << nodePtr->name.substr(0,2);
        display(nodePtr->left, level + 1);
    }
}

void BinaryTree::display()
{
	display(root, 1);
}