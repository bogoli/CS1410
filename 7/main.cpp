// Lia Bogoev
// A01240372	
// CS1410 - Assignment 7

#include <iostream>
#include <fstream>

// started working 6:30 --> 7:00

using namespace std;

void printMenu(){
	cout << endl << endl;
	cout << "*** Network of My Friends ***" << endl;
	cout << "A: Add a Friend" << endl;
	cout << "R: Remove a Friend by ID Number" << endl;
	cout << "M: Modify a Friend’s Information by ID Number" << endl;
	cout << "S: Search Interests" << endl;
	cout << "D: Display “myNetwork.dat” Database Information" << endl;
	cout << "L: List the Oldest and the Youngest Friends’ Information" << endl; 
	cout << "E: Exit" << endl;
	cout << "choose: ";
}

int main(int argc, char const *argv[])
{
	// menu and choice stuff, keeping the program running
	char menuChoice;
	char fileChoice;
	bool programRunning = false;

	// FILE SETTING UP: file handler, binary flags, etc
	fstream file("myNetwork.dat");
	// fstream file("myNetwork.dat", ios::in|ios::out|ios::binary);
	file.open("myNetwork.dat", ios::out|ios::in|ios::binary|ios::app);

	cout << "file.fail() = " << file.fail() << endl;

	if(file == 0){
		// the file doesn't exist yet 
		cout << "The file did not exist, creating a new file. \n";

		// open the same file as only output, which creates a file
		file.open("myNetwork.dat", ios::out);
		// close the file, and reopen with all the flags
		file.close();
		file.open("myNetwork.dat", ios::out|ios::in|ios::binary);

		// start the while loop
		programRunning = true;
	}

	else if(file != 0){
		cout << "The file exists, would you like to replace the contents? (Y/N): ";
		cin >> fileChoice;




	} // end else (the file is working)


	// the big while loop
	while(programRunning == true){
		printMenu();
		cin >> menuChoice;

		switch(menuChoice){
			case 'A':
			case 'a':
				// This option should not ask the user for an ID number. Instead, it should 
				// report to the user the unique ID that the program has just assigned. This
				// unique ID should be the file record or object number. Add the new Friend’s 
				// information to the right position (i.e., the end) of the “myNetwork.dat” file.
				cout << "\t\tAdd a friend \n";
				break;

			case 'R':
			case 'r':
				// Note: Once the specified friend is deleted, all friend records after this 
				// deleted friend should be moved forward by one record. 
				cout << "\t\tremove a friend\n";
				break;

			case 'M':
			case 'm':
				cout << "\t\tmodify a friend\n";
				break;

			case 'S':
			case 's':
				// Search through the database to find friends whose interests match with 
				// the input keyword (case insensitive) and output the friends’ screen name 
				// together with his/her ID number.
				cout << "\t\tsearch interests\n";
				break;

			case 'D':
			case 'd':
				// Provide a summary report of all actual Friend objects in “myNetwork.dat”.
				cout << "\t\tdisplay database\n";
				break;

			case 'L':
			case 'l':
				// Provide a summary report of the oldest and youngest 
				// Friend objects in “myNetwork.dat” in order. That is, 
				// the oldest friends are listed before the youngest friends.

				cout << "\t\tlist friends\n";
				break;

			case 'E':
			case 'e':
				cout << "\t\t - - - Exiting program - - - \n";
				file.close();
				exit(0);
				break;

			default: 
				cout << "\t\t - - - - INVALID INPUT - - - - \n";
				break;

		} // end switch 
		
	} // end while program running 

	return 0;
}







