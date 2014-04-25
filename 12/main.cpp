// Lia Bogoev
// A01240372
// CS1410

#include <iostream>
#include <fstream>
#include "BSTree.h"
using namespace std;

int main(int argc, char const *argv[])
{
	/*
	vector<string> a;
	ifstream fin;
	string word;

	fin.open(" ", ios::in);

	while(fin>> word){
		a.push_back(word); // pushing onto the end of the stack
	}	
	*/


/* Example for Chapter 19: Binary Trees
// This program demonstrates several basic operations of the Binary Search Tree
// All these basic operations are implemented using recursive functions
// Note: The delete function implements the better solution as explained in slide 16
// For simplicity, we assume that there are no whitespaces in the name
*/


	BSTree tree ;
	string thisname ;
	
	char option[2] ;
	bool done = false ;

	while (!done)
	{	
		cout << "Enter option: (I)nsert, (D)elete, (S)earch, (P)rint, (E)xit " ;
		cin >> option ;
		
		switch (option[0])
		{	
			case 'I':
			case 'i':	
				cout << "Enter name: " ;
				cin >> thisname ;  
				tree.Insert(thisname) ;
				break ;

			case 'D':
			case 'd':	
				cout << "Enter name: " ;
				cin >> thisname ;
				tree.Delete(thisname) ;
				break ;

			case 'S':
			case 's':
				cout << "Enter name: " ;
				cin >> thisname ;
				if (tree.Search(thisname))
					cout << "Name is found" << endl ;
				else cout << "Name is not found" << endl ;
				break;

			
			case 'P':
			case 'p':
				cout << tree.Traverse() << endl ;
				break ;

			case 'E':	
			case 'e':
				done = true ;
		}
	}

	return 0;
}
/*
randomShuffle(a.begin(), a.end()){
	BSTree b;
	BStree a;
	b.Traverse();
	a.Traverse();
}*/
