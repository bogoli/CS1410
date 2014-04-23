// Lia Bogoev
// A01240372
// CS1410

#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<string> a;
	ifstream fin;
	string word;

	fin.open(" ", ios::in);

	while(fin>> word){
		a.push_back(word); // pushing onto the end of the stack
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