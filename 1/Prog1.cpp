// Lia Bogoev
// A01240372
// CS 1410, Assignment 1

#include <iostream>
#include <cctype>
#include <string>
#include "Friend.h"
#include "Friend.cpp"

using namespace std;

int main(int argc, char const *argv[])
{
	// declare variables 
	const int NUM = 5; // number of friends in the network
	char c; // input char
	bool programRunning = true; // to keep the menu up
	string searchterm;

	// declare an array of Friend structures:
	Friend friendList[NUM]; 

	// set each screenName and interest for each friend in the array to EMPTY
	// set age to 0 
	for (int i = 0; i < NUM; i++){
		friendList[i].screenName = "EMPTY";
		friendList[i].age = 0;
		friendList[i].interests = "EMPTY";
	}

	// Display the welcome message on start
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n";
	cout << "               WELCOME TO MY FRIEND NETWORK! \n";
	cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&& \n";


	while(programRunning!=false){
		// Display the menu on start, select option 
		DisplayMenu();
		cin >> c;
		
		// make c lower case and check for errors
		if(c >= 'A' && c <= 'Z'){
			c = tolower(c);
		}
		else if(c >= 'a' && c <= 'z'){
			c = tolower(c);
		}

		else{
			// c is not valid 	
			cout << "\n==============================================================\n";
			cout << "    Sorry, that is not a valid input. Please try again.\n";
			cout << "==============================================================\n\n";
			c = '\n';
		}

		// make the menu actually do stuff
		switch(c){
			case 'a': 	
				// add a friend
				AddFriend(friendList, NUM);
				break;

			case 'r': 
				// remove a friend
				DisplayFriend(friendList, NUM);
				RemoveFriend(friendList, NUM);
				break;

			case 's': 
				// search interests
				cout << "Search: ";
				cin.ignore();
				getline(cin, searchterm, '\n');
			 	SearchInterest(friendList, NUM, searchterm);
				break;

			case 'd':
				// display all friends
				DisplayFriend(friendList, NUM);
				break;

			case 'l':
				// display friends in alphabetical order
				ListFriend(friendList, NUM);
				break;

			case 'c':
				// calculate average age of all friends
				cout << "\n\n";
				cout << "                The average age is: " << ReportAge(friendList, NUM) << endl;
				cout << "\n\n";
				break;

			case 'e':
				exit(1);
			default:		
				break;
		} // end switch statement

	} // end while loop for menu


	cout << endl;
	return 0;
} // end of main



// getline(cin, my_string, '\n');





