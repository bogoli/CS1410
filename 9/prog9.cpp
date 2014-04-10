// Lia Bogoev
// A01240372 
// CS1410 - Assign 9 

#include <iostream> 
#include "TUStack.h"
using namespace std;

int main()
{
	try{
		TUStack myStack = TUStack(2);

		myStack.Push(1);
		myStack.Push(2);

		
		myStack.print();
		cout << endl;
		myStack.print();

	}
	catch (TUStack::outOfBound exception){	
		cout << "Error Report --------------------------------------" << endl ;
		cout << "input index is: " << exception.index << endl ;
		cout << "array size is: " << exception.size << endl ;
		cout << "exception nature: " << exception.message << endl ;
	}
	catch (TUStack::emptyStack exception){	
		cout << "Error Report --------------------------------------" << endl ;
		cout << "input index is: " << exception.index << endl ;
		cout << "array size is: " << exception.size << endl ;
		cout << "exception nature: " << exception.message << endl ;
	}	
	catch (TUStack::fullStack exception){	
		cout << "Error Report --------------------------------------" << endl ;
		cout << "input index is: " << exception.index << endl ;
		cout << "array size is: " << exception.size << endl ;
		cout << "exception nature: " << exception.message << endl ;
	}
	catch (TUStack::duplicateItem exception){	
		cout << "Error Report --------------------------------------" << endl ;
		cout << "input index is: " << exception.index << endl ;
		cout << "array size is: " << exception.size << endl ;
		cout << "exception nature: " << exception.message << endl ;
	}

	return 0;
}