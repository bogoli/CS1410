// A linked-list of numbers
#ifndef _LLIST_H
#define _LLIST_H

#include <string>
#include <iostream>
using namespace std;

// Create a data type for the linked list node
class ListNode{  
public:	
	ListNode();
	ListNode(int n);

	int number;
	ListNode *next;
}; 

class LList{  
private:
	ListNode *head;

public:
	LList();

	void Insert(int n);	// insert a new number in order
	void Delete(int n);	// delete a number
	void Display();		// display list in order
};

#endif