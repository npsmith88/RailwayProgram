#include <string>
#include <iostream>
#include <list>
using namespace std;

#ifndef CARLIST_H
#define CARLIST_H

class CarList
{
private:
	struct CarNode
	{
		string name, description;
		struct CarNode *next;
		struct CarNode *prev;
	};

	CarNode *head;

public:
	CarList() { head = NULL; }
	~CarList();
	void appendNode(string, string);
	void insertNode(string, string);
	void deleteNode(string, string);
	void displayList() const;
};
void CarList::appendNode(string n, string d)
{
	CarNode *newNode;
	CarNode *nodePtr;
	newNode = new CarNode;
	newNode->name = n;
	newNode->description = d;
	newNode->next = NULL;
	if (!head)
	head = newNode;
	else
	{
		nodePtr = head;
		while (nodePtr->next)
		nodePtr = nodePtr->next;
		nodePtr->next = newNode;
	}
}
void CarList::displayList() const
{
	 CarNode *nodePtr;
		 nodePtr = head;
		 while (nodePtr)
		 {
			 cout << nodePtr->name << endl;
			 cout << nodePtr->description << endl;
			 nodePtr = nodePtr->next;
		 }
}
void CarList::insertNode(string n, string d)
 {
	 CarNode *newNode;
	 CarNode *nodePtr; 
	 CarNode *prevNode = NULL;
		 newNode = new CarNode;
	 newNode->name = n;
	 newNode->description = d;
		 if (!head)
		 {
		 head = newNode;
		 newNode->next = NULL;
		 }
	 else 
		 {
			 nodePtr = head;
			 prevNode = NULL;
			 while (nodePtr != NULL && nodePtr->name != n)
			 {
			 prevNode = nodePtr;
			 nodePtr = nodePtr->next;
			 }
			 if (prevNode == NULL)
		{
			head = newNode;
			 newNode->next = nodePtr;
			 }
		 else
			 {
			 prevNode->next = newNode;
			 newNode->next = nodePtr;
			 }
		 }
}
void CarList::deleteNode(string n, string d)
{
	CarNode *nodePtr;
	CarNode *prevNode;
	if (!head)
		return;
	if (head->name == n)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		while (nodePtr != NULL && nodePtr->name != n)
		{
			prevNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if (nodePtr)
		{
			prevNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
}
CarList::~CarList() {
			  CarNode *nodePtr; 
			  CarNode *nextNode; 
				  nodePtr = head;
				  while (nodePtr != NULL)
				  {
					 nextNode = nodePtr->next;
					 delete nodePtr;
				 nodePtr = nextNode;
				 }
}
#endif