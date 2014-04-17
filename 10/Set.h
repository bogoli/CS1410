// A linked-list of numbers
#ifndef _Set_H
#define _Set_H

#include <string>
#include <iostream>
using namespace std;

// Create a data type for the linked list node

class Set{  
private:
	class ListNode{  
	private:
		void clearNextNode(){ 
			if (next != NULL) { 
				delete next; 
			} 
		}
	public:	
		ListNode();
		ListNode(int n);
		~ListNode();
		int number;
		ListNode *next;
	}; 

	ListNode *head;

public:
	Set();
	~Set();

	void Insert(int n);	// insert a new number in order
	void Delete(int n);	// delete a number
	void Display();		// display list in order
	bool Find(int n); // find an element in the list

	
	// Exception class
	class duplicateItem{
	public:
		int number;
		string message;

		duplicateItem(int n, string m){
			number = n;
			message = m;
		}
	};
};

#endif