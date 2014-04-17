
// A linked list of numbers


// and it's useful if you add a destructor that deletes next if next != NULL to Set
// that way you can just delete head; if head != NULL in your Set class's destructor

#include "Set.h"

Set::ListNode::ListNode(){
	number = 0;
	next = NULL ;
}

Set::ListNode::ListNode(int n){   
	number = n ;
	next = NULL ;
}

Set::ListNode::~ListNode(){ 
	clearNextNode(); 
}

Set::Set(){    
	head = new ListNode (0);
	head->next = new ListNode (100);
}

Set::~Set(){
	
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
		throw duplicateItem(n, "Duplicate Item");
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
	}

	// the list has a node with the current data s
	// delete the node
	if (here->next != NULL)
	{	
		prev->next = here->next ;
		delete here ;
	}
}

void Set::Display(){    
	ListNode *here = head->next ;			// here is the first real node
	
	while (here->next != NULL)				// here->next==NULL means that here is the last real node
	{     
		cout << here->number << endl ;
		here = here->next ;
	}
}

bool Set::Find(int n){	
	ListNode *here = head->next ;
	ListNode *prev = head ;
	
	while (n != here->number && here->next != NULL) // here->next==NULL means that here is the last real node
	{	
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


