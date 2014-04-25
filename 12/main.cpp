// Lia Bogoev
// A01240372
// CS1410

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "BSTree.h"
using namespace std;

int main(int argc, char const *argv[])
{
	// DICTIONARY STUFF
	vector<string> dictVector;
	ifstream fin;
	string dictWord;

	fin.open("dictionary.txt", ios::in);

	while(fin >> dictWord){
		dictVector.push_back(dictWord); // pushing onto the end of the stack
	}	

	fin.close();
	// shuffle the vector
	random_shuffle(dictVector.begin(), dictVector.end());

	// make a dictionary tree
	BSTree dictTree;

	// insert the shuffled vector into the tree (shuffled so tree is balanced)
	for (int i = 0; i < dictVector.size(); i++){
		dictTree.Insert(dictVector[i]);
	}

	// dictTree.Traverse();  // print out the dictionary

	// OUTPUT THE SIZE OF THE TREE

	// READ IN THE LETTER 
	string letterWord;
	fin.open("letter.txt", ios::in);

	cout << "These words are misspelled: \n\n" ;
	while(fin >> letterWord){
		
		for(int i = 0; i < letterWord.length(); ++i){
			// make words in the letter lowercase
			char c = tolower(letterWord[i]);
			letterWord[i] = c;
		}
		
		if(dictTree.Search(letterWord) == false){
			cout << "\t" << letterWord << endl;
		}
		
	}	

	/*

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
*/
	return 0;
}