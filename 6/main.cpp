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
		cout << "\t" << environ[k] << endl;     // -------- UNCOMMENT LATER
		
		k++; 
	}
	cout << endl << endl;

	// close the output file
	fout.close(); 

	// use the same output file as the input file 
	ifstream fin;
	fin.open("environment.txt"); 

	if(fin.fail()){
		// if the file can't be found
		cout << "Could not find file.\n";
	}
	else{
		// else, the file is working: 

		// make a character array to store the next line
		char line[100];

		// make a map to store all the words
		map<string, int> words;

		// temp variable to hold the next potential word
		string temp;
		// word variable to enter into the words map
		string word;

		while(!fin.eof()){
			// get the next line
			fin.getline(line,100);

			// make it into a string
			string lineStr(line);

			for(int i = 0; i < lineStr.length(); ++i){
				// for each letter in the line, if it's alpha numeric and not a space: 
			
				if(isalnum(lineStr.at(i)) && !isspace(lineStr.at(i))){
					// add it to the temp string
					temp.append(1, lineStr.at(i));

				}
				if(!isalnum(lineStr.at(i)) ){
					// if it's not alphanumeric, make whatever is temp the word
					// add the word to the map, and set temp to "" (empty)

					if(temp.length() > 1){
						word = temp;
						words[word]+=1;
						temp = "";
					}

				}

			}
			// need this line to add the last word to the map 
			word = temp;
			words[word] += 1;
		} // end while reading the file 

		// finding strings in the map that aren't words
		for(map<string, int>::const_iterator it = words.begin(); it != words.end(); ++it){			
			if (it->first.length() == 1){
				// if the word is shorter than 2 erase it
				words.erase(it);
			}
			else{
				if( (it->first.find_first_of(ALPHABET,0)) == std::string::npos){
					words.erase(it);
				}
			}
		}// end for loop that clears out non-words

		// to count the number of words
		int count = 0;
		
		for(map<string, int>::const_iterator i = words.begin(); i != words.end(); ++i){			
			// prints out the entire map
			cout << fixed;
			cout << setprecision(0);
			cout << left << setw(30) << i->first << " " << i->second << endl;
			++count;  // up the count
		}
		// output the number of words
		cout << "\n\n\tNumber of words: " << count << endl << endl;

	} // end else (file is open)

	// close the input file for now 
	fin.close();

	// ================================================================== Searching

	// open the file again
	fin.open("environment.txt");
		if(fin.fail()){
			// if the file can't be found
			cout << "Could not find file.\n";
		}

		else{
			// else, the file is working: 
			char line[100];
			char search[40];

			cout << "Please enter the string you'd like to search for (up to 40 char): "; 
			cin >> search;

			bool end = false;
			while(!end){
				// convert the cstring to all uppercase
				char c;
				int i = 0; 
				while (search[i]){
	    			c = search[i];
	    			search[i] = toupper(c);
	    			++i;
	    		}

	    		// reset i for later
	    		i = 0;

	    		// convert c-string to string
	    		string searchString(search);

	    		if ( (searchString.find("END") != std::string::npos) || searchString == ""){
	    			end = true;
	    		}
				
				while(!fin.eof()){
					// get the next line
					fin.getline(line,100);	

					// convert line to all uppercase
					char d;
					int j = 0;
					while (line[j]){
		    			d = line[j];
		    			line[j] = toupper(d);
	    				++j;
		    		}

		    		// convert line to from a cstring to a string
					string lineStr(line);

					// cout << searchString;
					if( (lineStr.find(searchString)) != std::string::npos ){
						cout << lineStr << endl;
					}
				}
				// need to clear the end of file flag so that the file starts to read over
				// every time that you search
				fin.clear();
				fin.seekg(0, ios::beg);

				// redisplay the prompt and get input 
				cout << "Search (up to 40 char): "; 
				cin >> search;

			} // end while(!end)

		} // end else



	cout << endl;
return 0;

}