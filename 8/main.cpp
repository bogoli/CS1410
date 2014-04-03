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
bool findPath(char** m, int r, int c, int sR, int sC){
	if (sR >= r || sC >= c){
		// check bounds first
		return false;
	}
	if(m[sR][sC] == 't'){
		// treasure! 
		return true;
	}
	
	if(m[sR][sC] == '.'){

		m[sR][sC] = '+'; 

		if(findPath(m, r, c, sR+1, sC) == true){
			// north
			cout << sR << " " << sC << endl;
	 		return true;
		}
		
		if(findPath(m, r, c, sR, sC+1) == true){
			// west
			cout << sR << " " << sC << endl;
	 		return true;
		}

		if(findPath(m, r, c, sR-1, sC) == true){
			// south
			cout << sR << " " << sC << endl;
	 		return true;
		}


		if(findPath(m, r, c, sR, sC-1) == true){
			// east
			cout << sR << " " << sC << endl;
	 		return true;
		}
	}

	return false;
}


int main(int argc, char const *argv[])
{

	cout << "How many levels did the cannonball pyramid have? ";
	int levels;
	cin >> levels;
	cout << "There are " << CountCannonBalls(levels) << " cannonballs in the pyramid. \n\n";

	cout << "Input a number to convert to binary: ";
	int number; 
	cin >> number;
	cout << "Binary: ";
	PrintBinary(number);
	cout << endl << endl;

	cout << "Input a (large-ish) integer: ";
	int integer;
	cin >> integer;
	cout << "Sum of digits: " << ComputeSumOfDigits(integer);


	fstream file("maze.txt", ios::in);
	char ** maze;
	int rows, cols, startRow, startCol;

	if(file.is_open()){
		cout << "\n\nFile opened successfully.\n";

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


	// output the maze
	for(int i = 0; i < rows; ++i){
		for(int j = 0; j < cols; ++j){
			cout << maze[i][j];
		}
		cout << endl;
	}
	cout << endl;


	// solve the maze
	int solved = findPath(maze, rows, cols, startRow, startCol);

/*
Mazes tested: 
// maze that I created
	15 15
	1 2 
	XXXXXXXXXXXXXXX
	XX.XXXXXX....XX
	XX....XXX.XX.XX
	XXXX.XXXX....XX
	XX...XXXX.XX.XX
	XXXX.X....XX.XX
	XXX..X.XXXXX.XX
	XXX.XX.XX....XX
	XXX....XX.XXXXX
	XXXXXXXXX...XXX
	XXX.......XXXXX
	XXX.XX.XXX...XX
	XXX....XXX.X.XX
	XXXXXX.....XtXX
	XXXXXXXXXXXXXXX

// example maze
	11 10
	9 4 
	XXXXXXXXXX
	XX...tX..X 
	XX.XXXX.XX 
	XX.......X 
	XXXXXXX.XX 
	X....XX.XX 
	X.XX.....X 
	X...XX.XXX 
	XXX..XXXXX 
	XXXX....XX 
	XXXXXXXXXX



*/


	// destroy the maze
	for (int i = 0; i < rows; ++ i){
		delete maze[i];
	}
	delete maze;

	cout << endl;
	return 0;
}