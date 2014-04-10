// Lia Bogoev
// A01240372 
// CS1410 - Assign 9 

#include <iostream> 
#include "TUStack.h"
using namespace std;

int main()
{
	try{
		// integer stack example --> pushing a duplicate value
		cout << "Integer stack example: duplicate value exception\n";
		TUStack<int> myIntStack(5);

		myIntStack.Push(1);
		myIntStack.Push(1);
		
		myIntStack.print();
		cout << endl;

	}
	
	catch (TUStack<int>::duplicateItem exception){	
		cout << "Error Report --------------------------------------" << endl;
		cout << "input index is: " << exception.index << endl;
		cout << "array size is: " << exception.size << endl;
		cout << "duplicate item is: " << exception.duplicateValue << endl;
		cout << "exception: " << exception.message << endl;
		cout << endl << endl;
	}


	try{
		// string stack example --> out of bounds (index too large)
		cout << "String stack example: out of bounds exception (index too large) \n";
		TUStack<string> myStringStack(3);

		myStringStack.Push("hi");
		myStringStack.Push("hello");
		myStringStack.Push("what's up");

		myStringStack.print();

		// trying to print a value with index larger than possible
	 	cout << myStringStack[6] << endl;
		cout << endl;

	}
	catch(TUStack<string>::outOfBound exception){
		cout << "Error Report --------------------------------------" << endl;
		cout << "input index is: " << exception.index << endl;
		cout << "array size is: " << exception.size << endl;
		cout << "exception: " << exception.message << endl;
		cout << endl << endl;
	}

	try{
		// int stack example --> out of bounds (index negative)
		TUStack<int> myIntStack(3);

		myIntStack.Push(1);
		myIntStack.Push(2);
		myIntStack.Push(3);

		myIntStack.print();

		// trying to print a value with index larger than possible
	 	cout << myIntStack[-2] << endl;
		cout << endl;

	}
	catch(TUStack<int>::outOfBound exception){
		cout << "Error Report --------------------------------------" << endl;
		cout << "input index is: " << exception.index << endl;
		cout << "array size is: " << exception.size << endl;
		cout << "exception: " << exception.message << endl;
		cout << endl << endl;
	}


	try{
		// int stack example --> full stack exception
		TUStack<int> myIntStack(3);

		myIntStack.Push(1);
		myIntStack.Push(2);
		myIntStack.Push(3);
		myIntStack.Push(4); // trying to push onto a full stack 

		myIntStack.print();
	}
	catch(TUStack<int>::fullStack exception){
		cout << "Error Report --------------------------------------" << endl;
		cout << "input index is: " << exception.index << endl;
		cout << "array size is: " << exception.size << endl;
		cout << "exception: " << exception.message << endl;
	}

	try{
		// int stack example --> empty stack exception
		TUStack<int> myIntStack(3);

		myIntStack.Push(1);
		myIntStack.Push(2);
		myIntStack.Push(3);

		cout << "pop value: " << myIntStack.Pop() << endl;
		cout << "pop value: " << myIntStack.Pop() << endl;
		cout << "pop value: " << myIntStack.Pop() << endl;
		cout << "pop value: " << myIntStack.Pop() << endl; 		// Popping off an empty stack

	}
	catch(TUStack<int>::emptyStack exception){
		cout << endl;
		cout << "Error Report --------------------------------------" << endl;
		cout << "input index is: " << exception.index << endl;
		cout << "array size is: " << exception.size << endl;
		cout << "exception: " << exception.message << endl;
		cout << endl << endl;
	}



	return 0;
}