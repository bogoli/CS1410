// Lia Bogoev 
// CS 1410 - Assignment 6

#include <iostream>
#include <fstream>

#include <cstring>
#include <string> 

using namespace std;

int main(){
	// output the progrmaming environment to a file
	ofstream fout("environment.txt");

	// this is the stuff that reads in the programming environment
	extern char **environ;
	int k = 0;

	while (environ[k] != NULL) {
		// output to the file
		fout << environ[k] << endl;
		// output to the console
		cout << "\t" << environ[k] << endl;
		k++; 
	}


	// use the same output file as the input file 
	ifstream fin;
	fin.open("environment.txt"); 

	if(fin.fail()){
		cout << "Could not find file.\n";
	}
	else{
		cout << "The file exists\n";

		char line[100];
		fin.getline(line,100);

		









		

		// cout << line << endl;
	}


	// close the file
	fout.close(); 
	fin.close();

return 0;

}