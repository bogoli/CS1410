#include <iostream>
using namespace std;

struct Friend{
	float age;
	string screenName;
	string interests;
};

bool IsBefore (Friend friend1, Friend friend2) ;

// from assignment description

void Swap (Friend &a, Friend &b);

void BubbleSort (Friend array[ ], int size);

// specifications from assignment descriptions, content mine
void AddFriend (Friend friends[], int size) ;

void RemoveFriend (Friend friends[], int size) ;

void SearchInterest (Friend friends[], int size, string keywords) ;

void DisplayFriend (Friend friends[], int size) ;

void ListFriend(Friend friends[], int size) ;

float ReportAge(Friend friends[], int size) ;

void DisplayMenu();

