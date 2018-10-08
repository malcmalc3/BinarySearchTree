//BST.h
//Declares the BST (Binary Search Tree) class
//Programmer: Malcolm Milton
//Date: 3/31/15

#ifndef BST_H
#define BST_H
#include "TNode.h"

class BST
{
	private:
		TNode* root; //Points to the root of the tree
		TNode* successor(TNode*); //Returns a pointer to the smallest node that is larger than the parameter node (smallest in the right sub-tree)
		TNode* predecessor(TNode*); //Returns a pointer to the largest node that is smaller than the parameter node (largest in the left sub-tree)
	public:
		BST(); //Constructor, initiates root to NULL
		~BST(); //Destructor, deletes all nodes from the tree
		void inOrder(TNode*); //Prints out the the nodes using an in order algorithm (left, root, right)
		void preOrder(TNode*); //Prints the nodes using a pre order algorithm (root, left, right)
		void postOrder(TNode*); //Prints out the nodes using a post order algorithm (left, right, root)
		void order(int); //Function to provide access to the root for printing an order function
		void bstInsert(int); //Inserrts a new node in the correct place, if it doesn't already exist. Parameter is the new int to insert
		void bstDelete(int); //Deletes the node linked to the parameter from the tree
		TNode* bstSearch(int); //Searches for the node with the number of the parameter and returns it
		TNode* bstSearchParent(int); //Searches for the node with the number of the parameter and returns its parent
};

#endif
