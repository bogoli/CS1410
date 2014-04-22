
// A linked list of numbers


// and it's useful if you add a destructor that deletes next if next != NULL to Set
// that way you can just delete head; if head != NULL in your Set class's destructor

#include "Set.h"

Set::ListNode::ListNode(){
	number = 0;
	next = NULL ;
}

Set::ListNode::ListNode(int n){   
	number = n;
	next = NULL;
}

Set::Set(){    
	head = new ListNode (0);
	head->next = new ListNode (100);
}

Set::Set(const Set& origSet){
	copySet(origSet);
}
Set::~Set(){
	clearSet();
}

void Set::Insert (int n){	
	ListNode *newnode = new ListNode(n);

	ListNode *here = head->next ; // First real node
	ListNode *prev = head;

	while (n > here->number){  // Find where the number goes	
		prev = here ;
		here = here->next ;
	}
	if (here->number == n){	
		throw DuplicateException(n, "Duplicate Item");
	}

	prev->next = newnode;
	newnode->next = here;
}

void Set::Delete (int n){	
	ListNode *here = head->next ;
	ListNode *prev = head ;
	
	while (n != here->number && here->next != NULL) // here->next==NULL means that here is the last real node
	{	
		prev = here ;
		here = here->next ;


		if (here->next != NULL){	
			prev->next = here->next ;
		delete here ;
	}
	}

	
}

void Set::Print() const{    
	ListNode *here = head->next ;			// here is the first real node
	
	while (here->next != NULL)				// here->next==NULL means that here is the last real node
	{     
		cout << here->number << " " ;
		here = here->next ;
	}
	cout << endl;
}

bool Set::Find(int n) const{	
	ListNode *here = head->next ;
	ListNode *prev = head ;
	
	while (n != here->number && here->next != NULL){ // here->next==NULL means that here is the last real node	
		prev = here ;
		here = here->next ;
	}

	if (here->number == n){	
		cout << n << " was found in the set.\n";
		return true;
	}
	if(here->next == NULL){
		cout << n << " was NOT FOUND.\n";
	}
	return false;
}

int Set::Size(){
	ListNode *here = head->next ;
	ListNode *prev = head ;
	int counter = 0;
	
	while (here->next != NULL){ // here->next==NULL means that here is the last real node	
		prev = here;
		here = here->next;
		++counter;
	}

	return counter;
}


int Set::operator[](const int n) const{
	ListNode *here = head->next ;
	ListNode *prev = head ;
	int counter = 0;
	
	while (here->next != NULL){ // here->next==NULL means that here is the last real node	
		prev = here;
		here = here->next;

		if(counter == n){
			return here->number;
		}

		++counter;
	}

	// if out of bounds return -1
	return -1;

}

bool Set::operator<(const Set& S2) const{
	// returns true if S1 is a proper subset of S2 (S1 and S2 cannot be the same sets).
	ListNode *here = head->next;
	ListNode *prev = head;
	
	while (here->next != NULL){
		prev = here;
		here = here->next;

		if(S2.Find(here->number) == false){
			return false;
		}
	}


	return true;
}


Set Set::operator^(const Set& S2) const{
	ListNode *here = head->next;
	ListNode *prev = head;

	Set intersection;
	
	while (here->next != NULL){
		prev = here;
		here = here->next;

		if(S2.Find(here->number) == true){
			intersection.Insert(here->number);
		}
	}
	return intersection;
}


Set Set::operator+(const Set& S2) const{
	ListNode *here = head->next;

	Set addition = Set(S2);
	
	while (here->next != NULL){

		if(S2.Find(here->number) == false){
			addition.Insert(here->number);
		}

		here = here->next;

	}


	return addition;

}

Set Set::operator-(const Set& S2) const{
	ListNode *here = head->next;
	ListNode *prev = head;

	Set difference;
	
	while (here->next != NULL){
		prev = here;
		here = here->next;

		if(S2.Find(here->number) == false){
			difference.Insert(here->number);
		}
	}

	

	return difference;
}


istream& operator>>(istream& in, Set& origSet) { origSet.Insert(in); return in; }



