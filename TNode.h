//TNode.h
//Declaration of the TNode class
//Programmer: Malcolm Milton
//Date: 3/31/15

#ifndef TNODE_H
#define TNODE_H

class TNode
{
	private:
		TNode* parent; //Points to the parent node
		TNode* left; //Points to the left node
		TNode* right; //Points to the right node
		int data; //The integer that will be used for placement in the tree
	public:
		TNode(); //Initiates all pointers to NULL
		void printNode(); //Prints out the node's information
		void printInfo();
		friend class BST;
};

#endif
