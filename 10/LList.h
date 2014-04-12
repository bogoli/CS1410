// A linked-list of names
#ifndef _LLIST_H
#define _LLIST_H

#include <string>
#include <iostream>
using namespace std ;

// Create a data type for the linked list node
class ListNode
{  
public:	
	ListNode() ;
	ListNode(string s) ;

	string name ;
	ListNode *next;
}; 

class LList
{  
private:
	ListNode *head;

public:
	LList();

	void Insert (string s);	// insert a new name in order
	void Delete (string s);	// delete a name
	void Display ();		// display list in order
};

#endif