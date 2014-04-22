// Example 1 for Chapter 18: Stacks and Queues

// This example shows design of two kinds of stacks:
// 1) How to design a static stack using array.
// Note: This static stack is an upside down stack
// since the first element of the stack is placed at the first position (smallest address)
// 2) How to design a dynamic stack using linked list.


#include "IntStack.h"
#include <iostream> 
using namespace std;

int main(){
	int i ;

	// Test Case 1: Uncomment the following statement to test the static stack
	IntStack stack(5) ;  // Declare a stack which can hold five integers.

	// Test Case 2: Uncomment the following statement to test the dynamic stack
	// DIntStack stack ;

	try
	{
		cout << "Pushing five values " << endl ;
		for (i = 0; i < 5 ; i ++)
			stack.Push(i) ;
		
		cout << "Continuing pushing the value onto the stack " << endl ;
		stack.Push(100) ;

		cout << "Poping the value off the stack " << endl ;
		for (i = 0 ; i < 5 ; i ++)
			cout << stack.Pop() << endl ;

		cout << "Continuing popping the value off the stack " << endl ;
		cout << stack.Pop() << endl ;

		cout << "Continuing popping the value off the stack " << endl ;
		cout << stack.Pop() << endl ;

		cout << "Continuing pushing the value onto the stack " << endl ;
		stack.Push(200) ;

		cout << stack.Pop() << endl ;
	}
	
	catch (IntStack::IsFullException)
	{
		cout << "The Stack is Full " << endl ;
	}

	catch (IntStack::IsEmptyException)
	{
		cout << "The Stack is Empty " << endl ;
	}


	system("pause") ;
	return 0 ;
}


