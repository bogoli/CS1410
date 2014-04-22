/* main.cpp
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

*/


#include "Set.h"
#include <iostream>
using namespace std;

int main() {

Set S1, S2, S3;
S1.Insert(1);
S1.Insert(4);
S1.Insert(9);
S1.Insert(16);

S2.Insert(1);
S2.Insert(2);
S2.Insert(3);
S2.Insert(5);
S2.Insert(8);
S2.Insert(13);
S2.Insert(21);

S3.Insert(4);
S3.Insert(9);

try {
S2.Insert(1);
}
catch (Set::DuplicateException e) {
//cout << "Attempted to insert duplicate element: '" << e.value << "'" << endl; // Give warning to insert duplicate value
cout << "Attempted to insert duplicate element: '" << "'" << endl; // Give warning to insert duplicate value
}

if (S1.Find(16)==true)
{
cout<<"16 is found in S1" << endl;
S1.Print();
cout<<"Find() function is correct."<< endl; // this is correct
}
else
{
cout<<"16 is not found in S1"<< endl;
S1.Print();
cout<<"WARNING: Find() function is not correct."<< endl;
}

cout<<"Print S1 before deleting 16:"<< endl;
S1.Print();// 1, 4, 9, 16
cout<<"\n"<< endl;
// S1.Delete(16);
cout<<"Print S1 after deleting 16:"<< endl;
S1.Print();// 1, 4, 9
cout<<"\n"<< endl;
S1.Insert(16);
cout<<"Print S1 after inserting 16:"<< endl;
S1.Print();// 1, 4, 9, 16
cout<<"\n"<< endl;
cout
<< "S1: Size: " << S1.Size() << " Elements: " << endl //Size 4, // 1, 4, 9, 16
<< "S2: Size: " << S2.Size() << " Elements: " << endl //Size 7, //1, 2, 3, 5, 8, 13, 21
<< "S3: Size: " << S3.Size() << " Elements: " << endl // Size 2, // 4, 9
<< "S1 < S2: " << (S1 < S2 ? "true" : "false") << endl // false
<< "S3 < S1: " << (S3 < S1 ? "true" : "false") << endl // true
//<< "S1 ^ S2: " << (S1 ^ S2) << endl // 1
//<< "S1 + S2: " << (S1 + S2) << endl // 1, 2, 3, 4, 5, 8, 9, 13, 16, 21
//<< "S1 - S2: " << (S1 - S2) << endl // 4, 9, 16
<< "S3[1]: " << S3[1] << endl << endl // 9
<< "Insert a value into S3: ";

try {
cin >> S3; // input 91
cout << "Insertion Successful." << endl; // this is correct
}
catch (Set::DuplicateException e) {
//cout << "Attempted to insert duplicate element: '" << e.value << "'" << endl;
cout << "Attempted to insert duplicate element: '" << "'" << endl;
}
cout << "Updated S3: " << endl; // 4, 9, 91
S3.Print();

system("pause");
return 0;
}

