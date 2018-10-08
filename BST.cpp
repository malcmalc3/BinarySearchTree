//BST.cpp
//Defines member functions of the BST class
//Programmer: Malcolm Milton
//Date: 3/31/15

#include <iostream>
#include "BST.h"
#include "TNode.h"
using namespace std;

BST::BST() //Constructor, initiates root to NULL
{
	root = NULL; //Points root to nothing
}

BST::~BST() //Destructor, deletes all nodes from the tree
{
	int max; //To be used for getting the smallest value in the tree
	int min; //To be used for getting the largest value in the tree
	TNode *tempNode = root; //Creates a new pointer to the root of the tree

	while(tempNode->left != NULL) //Starts at the root node and stops when it has reached to the farthest left node (smallest value)
		tempNode = tempNode->left; //Points to the next left child
	min = tempNode->data; //Sets the minimum to the value of the smallest node

	tempNode = root; //Points to the root of the tree to start a new search for the largest node
	while(tempNode ->right != NULL) //Starts at the root node and stops when it has reached to the farthest right node (largest value)
		tempNode = tempNode->right; //Points to the next right child
	max = tempNode->data; //Sets the minimum to the value of the largest node

	for(int x=min; x<=max; x++) //Loops to delete from the smallest node to the largest node
		bstDelete(x); //Calls the function to delete the current node
	tempNode = root; //Points to the root of the tree
	delete tempNode; //Deletes the root of the tree

	cout << "Tree deleted" << endl << endl;
}

TNode* BST::successor(TNode* x) //Function to return a pointer to the successor node of the parameter node (successor is the smallest value in right sub-tree)
{
	TNode *tempNode = x; //Creates a pointer to the paramert node to start the search

	if(tempNode->right == NULL) //If there is no right sub-tree to look through
		tempNode = NULL; //Makes the pointer NULL to say that there is no successor
	else //If there is a right sub-tree to look through
	{
		tempNode = tempNode->right; //Sets tempNode to the right child of the parameter node (Could be the successor)
		
		while(tempNode->left != NULL) //Loop stops when it has gone the farthest left in the sub-tree (Farthest left is successor)
			tempNode = tempNode->left; //Points to the next left child
	}
	return tempNode; //Returns a pointer to the successor of the parameter node
}

TNode* BST::predecessor(TNode* x) //Function to return a pointer to the predecessor of the parameter node (predecessor is the largest node in left sub-tree)
{
	TNode *tempNode = x; //Creates a pointer to the parameter node to start the search

	if(tempNode->left == NULL) //If there is no left sub-tree to look through
		tempNode = NULL; //Makes the pointer null to tell calling function that there is no predecessor
	else //If there is a left sub-tree to look through
	{
		tempNode = tempNode->left; //Points to the left child of the parameter node (Could be the predecessor)
	
		while(tempNode->right != NULL) //Loop stops when it has gone the farthest right in the sub-tree (Farthest right is predecessor)
			tempNode = tempNode->right; //Points to the next right child
	}
	return tempNode; //Returns a pointer to the predecessor of the parameter node
}

void BST::inOrder(TNode* x) //Prints out the the nodes using an in order algorithm (left, right, root)
{
	if(x != NULL) //If there is a node to actually print out
	{
		inOrder(x->left); //For traversing to the left childs
		x->printNode(); //Prints the current node	Print using x->printInfo(); for seeing parent, left child, and right child of every node
		inOrder(x->right); //For traversing to the right childs
	}
}

void BST::preOrder(TNode* x) //Prints the nodes using a pre order algorithm (root, left, right)
{
	if(x != NULL) //If there is a node to actually print out
        {
		x->printNode(); //Prints the current node	Print using x->printInfo(); for seeing parent, left child, and right child of every node
                preOrder(x->left); //For traversing to the left childs
                preOrder(x->right); //For traversing to the right childs
        }
}

void BST::postOrder(TNode* x) //Prints out the nodes using a post order algorithm (left, right, root)
{
	if(x != NULL) //If there is a node to actually print out
        {
                postOrder(x->left); //For traversing to the left childs
                postOrder(x->right); //For traversing to the right childs
		x->printNode(); //Prints the current node	Print using x->printInfo(); for seeing parent, left child, and right child of every node
        }
}

void BST::order(int x) //Function to carry out which order to print with according to the parameter. This function provides access to the root node to start the recursive functions.
{
        if(root != NULL) //If there are nodes in the tree to print out
	{
		if(x == 1) //If the user wants to print using the in order traversal
		{
			cout << "In Order: " << endl;
                	return inOrder(root); //Calls the recursive function to print out the nodes, the first call is to the root
		}
		if(x == 2) //If the user wants to print using the post order traversal
		{
			cout << "Post Order: ";
			return postOrder(root); //Calls the recursive function to print out the nodes, the first call is to the root
		}
		if(x ==3) //If the user wants to print using the pre order traversal
		{
			cout << "Pre Order: ";
			return preOrder(root); //Calls the recursive function to print out the nodes, the first call is to the root
		}
	}
	else //If there are no nodes in the tree to print out
		cout << "The tree is empty";
}

void BST::bstInsert(int x) //Inserts a new node in the correct place, if it doesn't already exist. Parameter x = new int to insert.
{
	TNode *newNode = new TNode; //Creates a new TNode for adding tit to the tree
	newNode->data = x; //Makes the data of the new node equal to the value the user wants to add to the tree

	if(root == NULL) //If the tree is intially empty
	{
		root = newNode; //Makes the new node the root since it is the first node now
		cout << "New node inserted into tree" << endl << endl;
	}
	else if(x == root->data) //If the number the user wants to add is the root of the tree
		cout << "This node already exists" << endl << endl;
	else //If the number the user wants to add is not going to be the root, and it is no equal to the root
	{
		TNode *tempNode = bstSearchParent(x); //Creates a pointer and calls the function to point it to the parent of where the new node should be 
		
		if(x < tempNode->data) //If the new node is smaller than the parent then it should be the left child
		{
			if(tempNode->left == NULL) //If the space is availible to put a new node as the left child
			{
				tempNode->left = newNode; //Points the parent's left child pointer to the new node
				newNode->parent = tempNode; //Points the parent pointer of the new node to the parent
				cout << "New node inserted into tree" << endl << endl;
			}
			else //If the space is already filled by a node, then the node has the same data as the new node and new node will not be inserted
				cout << "This node already exists" << endl << endl;
		}

		if(x > tempNode->data) //If the new node is larger than the parent then it should be the right child
                {
                        if(tempNode->right == NULL) //If the space is availible to put a new node as the right child
                        {
                                tempNode->right = newNode; //Points the parent's right child pointer to the new node
                                newNode->parent = tempNode; //Points the parent pointer of the new node to the parent
                                cout << "New node inserted into tree" << endl << endl;
                        }
			else //If the space is already filled by a node, then the node has the same data as the new node and new node will not be inserted
				cout << "This node already exists" << endl << endl;
                }
	}
}

void BST::bstDelete(int x) //Deletes the node linked to the parameter from the tree
{
	if(root == NULL) //If there are no nodes in the tree
		cout << "The tree is empty" << endl << endl;
	else //If there are nodes in the tree to delete
	{
		TNode *deleteNode = bstSearch(x); //Creates a pointer and calls the function to point it to the node that will be deleted

		if(deleteNode != NULL) //If the node to be deleted actually exists in the tree
		{
			if(deleteNode->left == NULL && deleteNode->right == NULL) //If the node to delete is a leaf (has no children)
			{
				if(deleteNode->parent == NULL) //If the leaf has no parent then it is the root of the tree
				{
					root = NULL; //Points the root to nothing
					delete deleteNode; //deletes the node
				}
				else //If the leaf has a parent then it is not the root of the tree
				{
					if(deleteNode->data < deleteNode->parent->data) //If the leaf is the left child of its parent
						deleteNode->parent->left = NULL; //Sets the parent's left child to point to nothing
					else //If the leaf is the right child of its parent
						deleteNode->parent->right = NULL; //Sets the parent's right child to point to nothing
					delete deleteNode; //Deletes the leaf node
				}
			}
			else //If the node to delete is not a leaf (Has atleast one child)
			{
				TNode *tempNode = successor(deleteNode); //Creates a pointer and calls the function to point it to the successor of the node to delete
				if(tempNode == NULL) //If there is no successor of the node to delete
        	        	{
	                        	tempNode = predecessor(deleteNode); //Calls function to point to the predecessor of the node to delete
	        	                if(tempNode->data != deleteNode->left->data) //If the predecessor is not the immediate left child of the node to delete
        	                	{
                	        	        tempNode->parent->right = tempNode->left; //Fills the space that predecessor will be deleted from with its left sub-tree
                        		        if(tempNode->left != NULL) //If the predecessor has a child then the child's parent needs to point to new parent before deleting predecessor
							tempNode->left->parent = tempNode->parent; //Points the predecessor's child's parent to successor's parent (predecessor cannot have right child)
						deleteNode->data = tempNode->data; //Makes the data of the node to delete into the predecessor's data
                	                	delete tempNode; //Deletes the predecessor's node
		                        }
	        	                else //If the predecessor is the immediate left child of the node to delete
                	        	{
                        	       		tempNode->parent->left = tempNode->left; //Fills the space that predecessor will be deleted from with its left sub-tree
						if(tempNode->left != NULL) //If the predecessor has a child then the child's parent needs to point to new parent before deleting predecessor
							tempNode->left->parent = deleteNode; //Points the predecessor's child's parent to successor's parent (predecessor cannot have right child)
                                		deleteNode->data = tempNode->data; //Makes the data of the node to delete into the predecessor's data
	                	                delete tempNode; //Deletes the predecessor's node
        		                }
        	        	}
		                else
        	        	{
                		        if(tempNode->data != deleteNode->right->data) //If the successor is not the immediate right child of the node to delete
                	        	{
        	                        	tempNode->parent->left = tempNode->right; //Fills the space that successor will be deleted from with its right sub-tree
						if(tempNode->right != NULL) //If the successor has a child then the child's parent needs to point to new parent before deleting successor
							tempNode->right->parent = tempNode->parent; //Points the successor's child's parent to successor's parent (successor cannot have left child)
						deleteNode->data = tempNode->data; //Makes the data of the node to delete into the successor's data
        	                        	delete tempNode; //Deletes the successor's node
                	        	}
                        		else //If the successor is the immediate right child of the node to delete
                	        	{
        	                       		tempNode->parent->right = tempNode->right; //Fills the space that successor will be deleted from with its right sub-tree
						if(tempNode->right != NULL) //If the successor has a child then the child's parent needs to point to new parent before deleting successor
							tempNode->right->parent = deleteNode; //Points the successor's child's parent to successor's parent (successor cannot have left child)
		                                deleteNode->data = tempNode->data; //Makes the data of the node to delete into the successor's data
        	                        	delete tempNode; //Deletes the successor's node
                	        	}
                		}
			}
			cout << "Node deleted" << endl << endl;
		}
		else
			cout << "This node does not exist" << endl << endl;
	}
}

TNode* BST::bstSearch(int x) //Searches for the node according to the parameter and returns it (Used for deleting)
{
	TNode *tempNode = root; //Creates a pointer to the root of the tree
	bool found = false; //Variable to be used to stop the loop when the correct node is found

	while(!found) //Stops when the correct node is found
	{
		if(tempNode->data >= x) //If the node that is being searched is in the left sub-tree of the current node, or equal to the current node
		{
			if(tempNode->data == x) //If the curent node is the node that is being searched for
				found = true; //Makes found equal true because the node is found, the loop will now stop
			else if(tempNode->left != NULL) //If the node that is being searched for is in the left sub-tree of the current node
				tempNode = tempNode->left; //Points to the next left node
			else //If the left child of the current node is NULL then the node being searched for is not in the tree
			{
				tempNode = NULL; //Makes tempNode NULL so the calling function will know the node is not in the tree
				found = true; //Makes found true to stop the loop
			}
		}
		else if(tempNode->data <= x) //If the node that is being searched is in the right sub-tree of the current node, or equal to the current node
                {
                        if(tempNode->data == x) //If the curent node is the node that is being searched for
				found = true; //Makes found equal true because the node is found, the loop will now stop
			else if(tempNode->right != NULL) //If the node that is being searched for is in the right sub-tree of the current node
                                tempNode = tempNode->right; //Points to the next right node
			else //If the right child of the current node is NULL then the node being searched for is not in the tree
			{
				tempNode = NULL; //Makes tempNode NULL so the calling function will know the node is not in the tree
				found = true; //Makes found true to stop the loop
			}
                }
	}
	return tempNode; //Returns a pointer to the node that was being searched for, or returns NULL if it is not in the tree
}

TNode* BST::bstSearchParent(int x) //Searches for the parent of the node according to the parameter and returns it (Used for inserting)
{
	TNode *tempNode = root; //Creates a new pointer to the root of the tree
        bool found = false; //Variable to be used to stop the loop when the correct node is found

        while(!found) //Stops when the parent node is found
        {
                if(tempNode->data >= x) //If the parent node that is being searched is in the left sub-tree of the current node, or equal to the current node
                {
                        if(tempNode->left == NULL || tempNode->left->data == x) //If the parent is found then child will be NULL or the data of the child will already be in the tree
                                found = true; //Makes found equal true because the node is found, the loop will now stop
                        else //If the parent is not yet found
                                tempNode = tempNode->left; //Points to the next left child
                }
                else if(tempNode->data <= x) //If the parent node that is being searched is in the right sub-tree of the current node, or equal to the current node
                {
                        if(tempNode->right == NULL || tempNode->right->data == x) //If the parent is found then child will be NULL or the data of the child will already be in the tree
                                found = true; //Makes found equal true because the node is found, the loop will now stop
                        else //If the parent is not yet found
                                tempNode = tempNode->right; //Points to the next right child
                }
        }
        return tempNode; //Returns a pointer to the parent of the node that was given as a parameter
}
