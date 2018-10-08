//Lab6.cpp
//For testing Binary Search Tree
//Programmer: Malcolm Milton
//Date: 3/26/15

#include <iostream>
#include "BST.h"
#include "TNode.h"
using namespace std;

int menu(); //Function to ask user what option they would like to execute and returns the answer in integer form
int orderMenu(); //Function to ask which order the user wants to use while printing the nodes of the tree and returns the answer in integer form

int main()
{
	int number; //This integer will either be added to the tree or deleted from it
	int choice = 0; //Variable to make the loop run and execute the user's answer to the menu() function
	BST *tree = new BST; //Creates a new instance of the BST class and calls it tree

	while(choice != 4) //Loops until the user wants to quit (selects 4 in menu() function)
	{
		choice = menu(); //Calls function to ask user what to do with tree and saves the answer
		
		if(choice == 1) //If the user wants to insert a number into the tree
		{
			cout << "Please enter the number you would like to add to the tree: ";
			cin >> number; //Saves the user's answer in number
			tree->bstInsert(number); //Calls BST member function to insert the number into tree
		}
		else if(choice == 2) //If the user wants to delete a number from the tree
		{
			cout << "Please enter the number you would like to delete from the tree: ";
			cin >> number; //Saves the user's answer in number
			tree->bstDelete(number); //Calls BST member function to delete the number from the tree
		}
		else if(choice == 3) //If the user wants to print out the numbers in the tree
		{
			number = orderMenu(); //Calls function to ask user which order algorithm to use and saves the answer in number
			tree->order(number); //Calls the BST member function to print the nodes out based on which order the user wants
			cout << endl << endl;
		}
		else if(choice == 4) //If the user wants to quit the program
			cout << "Thank you for using this program" << endl << endl;
	}
	return 0;
}

int menu() //Function to ask user what they wan to do with the tree and returns the answer in int form
{
	int choice; //Variable used to save the user's answer
	
	cout << "1. Insert Element \n2. Delete Element \n3. Check by Printing \n4. Quit \nChoice: ";
	cin >> choice; //Saves the user's answer

	while(choice < 1 || choice > 4) //Loops until the user chooses 1, 2, 3, or 4
	{
		cout << "Please choose a valid choice: ";
		cin >> choice; //Saves the user's new answer
	}
	cout << endl;
	return choice; //Returns the user's choice
}

int orderMenu() //Function to ask the user which order algorithm they want the nodes of the tree to be printed out in and returns answer in int form
{
	int number; //Variable used to save the user's answer
	
	cout << "1. Inorder \n2. Postorder \n3. Preorder \nChoice: ";
	cin >> number; //Saves the user's answer
	
	while(number < 1 || number > 3) //Loops until the user chooses 1, 2, or 3
        {
                cout << "Please choose a valid choice: ";
                cin >> number; //Saves the user's new answer
        }
        cout << endl;
        return number; //Returns the user's choice
}
