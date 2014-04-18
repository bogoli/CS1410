// main.cpp
#include "Set.h"

int main()
{	
	Set mySet;
	char option;
	int thisnumber;
	bool keepGoing = false;

	while (keepGoing == false){	
		cout << "\tOptions: \n";
		cout << "\t(I)nsert \n";
		cout << "\t(F)ind \n";
		cout << "\t(D)isplay\n";
		cout << "\t(R)emove \n";
		cout << "\t(S)ize of Set\n";
		cout << "\t(C)ontinue  \n";
		cin >> option;
		cin.ignore();
		
		switch (option){	
		case 'I':
		case 'i':	
			try{
				cout << "Enter number: ";
				cin >> thisnumber;
				mySet.Insert(thisnumber);
			} catch(Set::duplicateItem e){
				cout << "duplicate item: " << e.number << endl;
				cout << "exception: " << e.message << endl;
			}
				break;

		case 'F':
		case 'f':
			cout << "What are you looking for? ";
			cin >> thisnumber;
			mySet.Find(thisnumber);
			break;
		
		case 'D':  
		case 'd':	
			mySet.Display();
			break;

		case 'R': 
		case 'r':	
			cout << "Enter a number: ";
			cin >> thisnumber;
			mySet.Delete(thisnumber);
			break;

		case 'S':
		case 's':
			cout << mySet.Size() << endl;
			break;

		case 'C':  
		case 'c':
			keepGoing = true;
		}
	}


	cout << "Driver for overloaded operators: \n";
	Set A = Set();
	A.Insert(1);
	A.Insert(2);
	A.Insert(3);
	A.Insert(4);

	Set B = A;  // overloaded = operator works
	
	Set C = Set();
	C.Insert(4);
	C.Insert(5);
	C.Insert(6);
	C.Insert(7);
	C.Insert(8);


	cout << "Set A: ";
	A.Display();
	cout << "Set B: ";
	B.Display();
	cout << "Set C: ";
	C.Display();

	Set D = A + C;
	D.Display();

return 0;	
}
