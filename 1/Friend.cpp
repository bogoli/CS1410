#include <iostream>
#include <string>
#include <cctype>
using namespace std;


// used in BubbleSort 
bool IsBefore (Friend friend1, Friend friend2){
//	if (friend1.screenName != "EMPTY"){
		if (friend1.screenName < friend2.screenName){
			return true;
		}
		else if(friend1.screenName == friend2.screenName){
			if(friend1.age < friend2.age){
			return true;
			}
			else{
				return false;
			}
		}
		else{
			return false;
		}

		cout << "IT'S NOT EQUAL TO EMPTY\n";
//	}

//	else{
//		return false;
//	}

}// end IsBefore

// used in BubbleSort
void Swap (Friend &a, Friend &b) {
	Friend temp; 
	temp = a; 
	a=b;
	b = temp;
}

// Used in ListFriend
void BubbleSort (Friend array[], int size) {
	bool done = false;
	while (!done) {
		done = true;
		for (int n=0; n<size-1; n++){
			if (! IsBefore (array[n], array[n+1])) {
				Swap (array[n], array[n+1]); done = false;
			} // end if
		size-- ;
		} // end for
	} // end while
}// end BubbleSort


void AddFriend (Friend friends[], int size){
	int emptyIndex;
	for(int i = size; i > -1; i--){
		if(friends[i].screenName == "EMPTY"){
			emptyIndex = i;
		}
		else if(friends[i].screenName != "EMPTY" && i == size - 1){
			cout << "\n\n\n           YOUR FRIEND NETWORK IS FULL. \n\n\n";
			return;
		}
	}	
	cout << "Please input a name: "; 
	string addName;
	cin.ignore();
	getline(cin, addName, '\n');
	friends[emptyIndex].screenName = addName;

	cout << "Please input an age: ";
	float addAge;

//	cin.ignore();
//	getline(cin, addAge, '\n');
	cin >> addAge;
	friends[emptyIndex].age = addAge;

	cout << "Please input interests: "; 
	string addInterests;
	cin.ignore();
	getline(cin, addInterests, '\n');
	friends[emptyIndex].interests = addInterests;
}


void RemoveFriend (Friend friends[], int size){
	cout << "Which friend would you like to remove? Enter the number: ";
	int i;
	cin >> i;
	friends[i].screenName = "EMPTY";
	friends[i].age = 0;
	friends[i].interests = "EMPTY";
}


void SearchInterest (Friend friends[], int size, string keywords){
	// keywords = tolower(keywords);
	for (int i = 0; i < size; i++){
	// 	friends[i].interests = tolower(friends[i].interests);
		if (friends[i].interests.compare(keywords) == 0){
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
			cout << "    # " << i << endl;
			cout << "    name:      " << friends[i].screenName << endl;
			cout << "    age:       " << friends[i].age << endl;
			cout << "    interests: " << friends[i].interests << endl;
			cout << endl;
		}
	}
}

// used in ListFriend
void DisplayFriend (Friend friends[], int size){
	int emptyCount = 0;
	for (int i = 0; i < 5; i++){
		if(friends[i].screenName != "EMPTY"){
			cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - \n";
			cout << "    # " << i << endl;
			cout << "    name:      " << friends[i].screenName << endl;
			cout << "    age:       " << friends[i].age << endl;
			cout << "    interests: " << friends[i].interests << endl;
			cout << endl;
		}
		else if (friends[i].screenName == "EMPTY"){
			++emptyCount;
			// cout << emptyCount; 
		}
	}
	if (emptyCount == size){
		cout << "\n\n\n           YOU HAVE NO FRIENDS IN THE NETWORK. \n\n\n";
	}

}


void ListFriend(Friend friends[], int size){
	// create a temporary array
	Friend tempArray[5];

	for (int i = 0; i < 5; i++){
		tempArray[i].screenName = friends[i].screenName;
		tempArray[i].age = friends[i].age;
		tempArray[i].interests = friends[i].interests;
	}

	BubbleSort(tempArray, 5);
/*
	for (int i = 0; i < 5; i++){
		cout << tempArray[i].screenName;
	}
*/
	DisplayFriend(tempArray, 5);
} // end of ListFriend

float ReportAge(Friend friends[], int size){
	float sum = 0; 
	int count = 0;
	for (int i = 0; i < size; i++){
		if (friends[i].age != 0){
			sum += friends[i].age;
			++count;
		}
	}
	if (count > 0){
		return sum/count; 
	}
	else{
		return 0 ;
	}

}



void DisplayMenu(){
	cout << "\nA: Add a Friend\n";
	cout << "R: Remove a Friend\n";
	cout << "S: Search Interests\n";
	cout << "D: Display All Friends\n";
	cout << "L: List All Friends in Alphabetic Order\n";
	cout << "C: Calculate the Average Age of All my friends\n";
	cout << "E: Exit\n";
	cout << "Please choose: ";
}