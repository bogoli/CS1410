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
		// end clearNextNode

		void copyNode(const ListNode& origNode) {
			number = origNode.number;
			if (origNode.next != NULL) {
				next = new ListNode(*origNode.next);
			}
			else {
				next = NULL;
			}
		} // end copyNode
	public:	
		ListNode();
		ListNode(int n);
		ListNode(const ListNode& origNode){copyNode(origNode);};
		~ListNode(){clearNextNode();};
		int number;
		ListNode *next;
	};  // end of ListNode subclass

	ListNode *head;
	void copySet(const Set& origSet) {head = new ListNode(*origSet.head);}
    void clearSet() { if (head != NULL) { delete head; } }

public:
	Set();
	Set(const Set& S);
	~Set();

	void Insert(int n);	
	void Insert(istream& in){ int n; in >> n; Insert(n); }

	void Delete(int n);	
	void Print() const;		
	bool Find(int n) const; 
	int Size(); 	
	int operator[](const int) const; 	// return the element with that index
	bool operator<(const Set&) const;  	// returns true if first is subset of second
	Set operator^(const Set&) const;	// returns a new set containing the intersection
	Set operator+(const Set&) const;
	Set operator-(const Set&) const;


	// Exception class
	class DuplicateException{
	public:
		int number;
		string message;

		DuplicateException(int n, string m){
			number = n;
			message = m;
		}
	};
};

istream& operator>>(istream&, Set&);


#endif