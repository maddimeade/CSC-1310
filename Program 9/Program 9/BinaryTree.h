/*********************************************************************************
 *     Title:   BinaryTree.h                                                     *
 *     Author:  Maddison Davenport                                               *
 *     Date:    March 29, 2018                                                   *
 *     Purpose: This is the specification file for the BinaryTree class, which   *
 *              is an implementation of a Binary Search Tree.  Each Tree Node    *
 *              stores a customer name (string) and the number of Krabby Patties *
 *              the customer ate.                                                *
 *********************************************************************************/
#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
using namespace std;


class BinaryTree
{
	private:
		struct TreeNode
		{
			int valuePatty;
			string name;
			TreeNode *left;
			TreeNode *right;
		};
		TreeNode *root;
		BinaryTree::TreeNode* insert(TreeNode *&nodePtr, TreeNode *&newNode);
		void destroySubTree(TreeNode *nodePtr);
		void makeDeletion(TreeNode *&nodePtr);
		void displayInOrder(TreeNode *nodePtr);
		void getLeast(TreeNode *nodePtr, int &leastPatties, string &leastName);
		void getMost(TreeNode *nodePtr, int &mostPatties, string &mostName);
		void getTotal(TreeNode *nodePtr, int &total);
		BinaryTree::TreeNode* rr_rotation(TreeNode *nodePtr);
		BinaryTree::TreeNode* ll_rotation(TreeNode *nodePtr);
		BinaryTree::TreeNode* lr_rotation(TreeNode *nodePtr);
		BinaryTree::TreeNode* rl_rotation(TreeNode *nodePtr);
		void display(TreeNode *nodePtr, int level);
	
	public:
		BinaryTree();
		~BinaryTree();
		void insertNode(string newName, int newPatty);
		void remove(string name);
		void deleteNode(string nameDelete, TreeNode *&nodePtr);
		void displayInOrder();
		int searchNode(string nameSearch);
		void getLeastNumPatties(string &leastName, int &leastPatties);
		void getMostPatties(string &mostName, int &mostPatties);
		int getTotalNumPatties();
		BinaryTree::TreeNode* balance(TreeNode *nodePtr);
		int height(TreeNode *nodePtr);
		int diff(TreeNode *nodePtr);
		void display();
	
};


#endif