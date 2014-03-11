// Lia Bogoev 
// CS 1410 - Assignment 6

#include <iostream>
#include <fstream>

#include <cstring>
#include <string>
#include <cstddef>
#include <iomanip>
#include <map>

using namespace std;

const string ALPHABET = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

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
				if(isalnum(lineStr.at(i)) && !isspace(lineStr.at(i))){
					// cout << lineStr.at(i) << ".....y" << endl; 
					temp.append(1, lineStr.at(i));

				}
				if(!isalnum(lineStr.at(i)) ){
					// cout << "\t\tn" << endl;
					if(temp.length() > 1){
						
						/*
						for(int j = 0; j < temp.length(); ++j){
							if(isalpha(temp.at(i))){
								// if there's at least one letter
								word = temp;
								words[word]+=1;
								temp = "";
							}
							else{ 
								// temp = "";
							} 
						}
						*/

						word = temp;
						words[word]+=1;
						temp = "";

					}
					// cout << word << " " << words[word] << endl; 
				}

			}
			// need this for the last word
			word = temp;
			words[word] += 1;


		} // end while

		for(map<string, int>::const_iterator it = words.begin(); it != words.end(); ++it){			
			if (it->first.length() == 1){
				// if the word is shorter than 2 erase it
				// cout << it->first << endl;
				words.erase(it);
			}
			else{
				if( (it->first.find_first_of(ALPHABET,0)) == std::string::npos){
					words.erase(it);
				}
			}
		}// end for loop that clears out non-words

	


		int count = 0;
		
		for(map<string, int>::const_iterator i = words.begin(); i != words.end(); ++i){			
			// prints out the entire map
			cout << fixed;
			cout << setprecision(0);
			cout << left << setw(20) << i->first << " " << i->second << endl;
			++count;
		}
		

		cout << "Number of words: " << count;
	} // end else (file is open)

	// close the file
	fout.close(); 
	fin.close();
	cout << endl;



return 0;

}