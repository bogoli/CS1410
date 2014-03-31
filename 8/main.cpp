// Lia Bogoev
// CS 1410
// Assignment 8

#include <iostream>
using namespace std;

// TASK 1
int CountCannonBalls(int levels){
	if(levels == 1){
		// cout << "levels == 1\n";
		return 1;
	}
	else if (levels > 1){
		// cout << "levels > 1\n";
		return (levels * levels) + CountCannonBalls(levels - 1);
	}
	else{
		return 0;
	}
}

// TASK 2
void PrintBinary(int num){
	if (num < 2){
		//cout << "num == 0\n";
		cout << num;
	}
	else{
		PrintBinary(num / 2);
		cout << (num % 2);
	}
}


// TASK 3
int ComputeSumOfDigits(int num){
	if(num < 10){
		return num;
	}
	else{
		return (num%10) + ComputeSumOfDigits(num/10);
	}
}

// TASK 4


int main(int argc, char const *argv[])
{
/*
	cout << "How many levels did the cannonball pyramid have? ";
	int levels;
	cin >> levels;
	cout << "There are " << CountCannonBalls(levels) << " cannonballs in the pyramid. \n\n";

	cout << "Input a number to convert to binary: ";
	int number; 
	cin >> number;
	cout << "Binary: ";
	PrintBinary(number);

	cout << "Input a (large-ish) integer: ";
	int integer;
	cin >> integer;
	cout << "Sum of digits: " << ComputeSumOfDigits(integer);
*/

	cout << endl;
	return 0;
}