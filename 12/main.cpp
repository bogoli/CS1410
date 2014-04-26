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

	// OUTPUT THE SIZE OF THE TREE
	cout << "\nsize of dictionary: " << dictTree.Size() << endl;

	// OUTPUT THE HEIGHT OF THE TREE
	cout << "height of dictionary: " << dictTree.Height() << endl << endl;

	// READ IN THE LETTER 
	string letterWord;
	fin.open("letter.txt", ios::in);

	cout << "These words are misspelled: \n\n" ;
	while(fin >> letterWord){
		
		for(int i = 0; i < letterWord.length(); ++i){
			switch(letterWord[i]){
				case '"':
				case ',':
				case ':':
				case '.':
				case '!':
				case '?':
				case '(':
				case ')':
					// replace with space
					letterWord[i] = ' ';
					break;
			}

			// make words in the letter lowercase
			char c = tolower(letterWord[i]);
			letterWord[i] = c;
		}
		
		if(dictTree.Search(letterWord) == false){
			cout << "\t" << letterWord << endl;
		}

	}


	// demonstrating member functions using first 10 randomized words
	BSTree A;

	A.Insert(dictVector[0]);
	A.Insert(dictVector[1]);
	A.Insert(dictVector[2]);

	cout << "\n\n A tree traversal: \n";
	A.Traverse();

	BSTree B = BSTree(A);

	cout << "\nTesting copy constructor. \nB tree traversal: \n";
	B.Traverse();
	cout << "size of B: " << B.Size() << endl;
	cout << "height of B: " << B.Height() << endl;

	cout << "\nInserting some more random words into B: \n";
	B.Insert(dictVector[3]);
	B.Insert(dictVector[4]);
	B.Insert(dictVector[5]);
	B.Insert(dictVector[6]);
	B.Insert(dictVector[7]);
	B.Insert(dictVector[8]);

	cout << "B tree traversal:\n";
	B.Traverse();
	cout << "new size of B: " << B.Size() << endl;
	cout << "new height of B: " << B.Height() << endl << endl;

	cout << "searching for word: " << dictVector[9] << ", which shouldn't be in either.\n";
	cout << "A: " << A.Search(dictVector[9]) << endl;
	cout << "B: " << B.Search(dictVector[9]) << endl;

	cout << "searching for word: " << dictVector[1] << ", which should be in both trees.\n";
	cout << "A: " << A.Search(dictVector[1]) << endl;
	cout << "B: " << B.Search(dictVector[1]) << endl;

	cout << "searching for word: " << dictVector[4] << ", which should be in B but not in A.\n";
	cout << "A: " << A.Search(dictVector[4]) << endl;
	cout << "B: " << B.Search(dictVector[4]) << endl;




	cout << endl;
	return 0;
}