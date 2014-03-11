// Lia Bogoev 
// CS 1410 - Assignment 6

#include <iostream>
#include <fstream>

#include <cstring>
#include <string>

#include <iomanip>
#include <map>

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
		// cout << "\t" << environ[k] << endl;     // -------- UNCOMMENT LATER
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
		

		map<string, int> words;
/*
		words["word"]=0;
		words["word"]+=1;
*/
		
		string temp;
		string word;

		// cout << "\tline before: \n" << lineStr << endl;;

		while(!fin.eof()){
			fin.getline(line,100);
			string lineStr(line);
			for(int i = 0; i < lineStr.length(); ++i){
				// cout << lineStr.at(i) << " "; 
				if(isalpha(lineStr.at(i)) ){

					// cout << lineStr.at(i) << ".....y" << endl; 
					temp.append(1, lineStr.at(i));

				}
				if(!isalpha(lineStr.at(i))){
					// cout << "\t\tn" << endl;
					if(temp.length() > 1){
						word = temp;
						temp = "";
						words[word]+=1;
					}

					// cout << word << " " << words[word] << endl; 
				}

			}
			word = temp;
			words[word] += 1;

			// cout << word << " " << words[word] << endl; 

		} // end while


		// cout << "\tTEMP IS:    " << temp << endl;

		/*
		cout << "length of line: " << linestr.length() << endl;
		cout << linestr << endl;
		*/
		
		// cout << line << endl;
		

		for(map<string, int>::const_iterator i = words.begin(); i != words.end(); ++i){
			cout << fixed;
			cout << setprecision(0);
			cout << left << setw(20) << i->first << " " << i->second << endl;
		}


	} // end else (file is open)


	// close the file
	fout.close(); 
	fin.close();
	cout << endl;
return 0;

}