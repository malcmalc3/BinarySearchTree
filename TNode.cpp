//TNode.cpp
//Defines member functions of the TNode class
//Programmer: Malcolm Milton
//Date: 3/31/15

#include <iostream>
#include "TNode.h"
using namespace std;

TNode::TNode() //Class constructor, initiates all pointers to NULL
{
	parent = NULL; //Initiates parent pointer to point to nothing
	left = NULL; //Initiates left pointer to point to nothing
	right = NULL; //Initiates right pointer to point to nothing
}

void TNode::printNode() //Function to print out the integer of the node
{
	cout << data << " "; //Prints out the integer using the private member int data
}

void TNode::printInfo()
{
	if(parent == NULL)
		cout << data << ": parent = NULL. ";
	else
		cout << data << ": parent= " << parent->data << ". ";

	if(left == NULL)
          	cout << " left= NULL. ";
        else
                cout << " left= " << left->data;

        if(right == NULL)
                cout << " right=  NULL";
        else
                cout << " right= " << right->data << endl;

	cout << endl;
}
