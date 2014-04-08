// Lia Bogoev
// A01240372 
// CS1410 - Assign 9 

#include <iostream> 
#include "TUStack.h"
using namespace std;

int main()
{
	TUStack myStack = TUStack(5);

	myStack.Push(5);
	cout << myStack.Pop() << endl;
	myStack.print();

	return 0;
}