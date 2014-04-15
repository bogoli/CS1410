
// A linked list of numbers


// and it's useful if you add a destructor that deletes next if next != NULL to LList
// that way you can just delete head; if head != NULL in your Set class's destructor

#include "LList.h"

ListNode::ListNode(){
	number = 0;
	next = NULL ;
}

ListNode::ListNode(int n){   
	number = n ;
	next = NULL ;
}

LList::LList(){    
	head = new ListNode (0);
	head->next = new ListNode (100);
}

ListNode::~ListNode(){ 
	clearNextNode(); 
}

// Steps for the Insert operation
// 1. create a new node
// 2. store data in the new node
// 3. find the first node x whose value is greater than the new value
// 4. insert the new node between the two existing nodes (x and the node before x)
void LList::Insert (int n){	
	ListNode *newnode = new ListNode(n) ;

	ListNode *here = head->next ; // First real node
	ListNode *prev = head;

	while (n > here->number){  // Find where the number goes	
		prev = here ;
		here = here->next ;
	}

	prev->next = newnode;
	newnode->next = here;
}

// Steps for the Delete operation
// 1. find the first node whose value is equal to the new value, or end of list

void LList::Delete (int n){	
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
// Steps for Display operation
// 1. Assign the head node "next" pointer to a "node pointer"
// 2. while "node pointer" is not NULL
//        display node data
//        update "node pointer" with "next node"
void LList::Display(){    
	ListNode *here = head->next ;			// here is the first real node
	
	while (here->next != NULL)				// here->next==NULL means that here is the last real node
	{     
		cout << here->number << endl ;
		here = here->next ;
	}
}
