// Lia Bogoev
// CS 1410
// Assignment 8

#include <iostream>
#include <fstream>
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

	fstream file("maze.txt", ios::in);
	char ** maze;
	int rows, cols, startRow, startCol;

	if(file.is_open()){
		cout << "File opened successfully.\n";

		// get size of maze and starting coordinates
		file >> rows;	// rows
		file >> cols;	// columns
		file >> startRow;	// start row
		file >> startCol;  	// start column

		// allocate the memory for the maze** 
		maze = new char*[rows];
		for (int i = 0; i < rows; ++ i){
			maze[i] = new char[cols];
		}

		// ready to read in the maze
		for(int i = 0; i < rows; ++i){
			for(int j = 0; j < cols; ++j){
				file >> maze[i][j];
			}
		}

		// finished with the file
		file.close();
	}
	else{
		cout << "Error. File open failed. \n";
	}

	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			cout << maze[i][j];
		}
		cout << endl;
	}



	// destroy the maze
	for (int i = 0; i < rows; ++ i){
		delete maze[i];
	}
	delete maze;

	cout << endl;
	return 0;
}