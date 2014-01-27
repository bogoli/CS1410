// Game.cpp
//#include "Game.h"


char** makeBoard(int rows, int cols){
	// create dynamically allocated 2D array
	char** board;  // 2 stars --> both dimensions are pointers

	// create new array of row number of pointers to chars
	board = new char*[rows];  
	
	for (int i = 0; i < rows; ++i){
		// make each element of pointers point to an array of cols # of chars 
		board[i] = new char[cols];  
	}

	// fill in array with spaces
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			board[i][j] = ' ';
		}
	}
	return board;
}

void printBoard(char**, int rows, int cols){
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			cout << "| "<< board[i][j] << " ";
		}
		cout << endl;
	}
}
