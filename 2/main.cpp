// Lia Bogoev
// CS 1410 - Assignment 2

/*
Note to the graders: 

I did what I could: I have a gameboard working and player functions working. 
I couldn't get the checker functions working. I had a really tough week, with a 
research conference on Thursday, and an exam, and a lot of things piled up.
Thank you for taking the time to give me partial credit for the work that I did. 
*/


// #include "Game.h"
#include <iostream>
using namespace std;

// FUNCTIONS 
char** makeBoard(int rows, int cols){
	// create dynamically allocated 2D array
	char** board;  // 2 stars --> both dimensions are pointers

	// create new array of col number of pointers to chars
	board = new char*[cols];  
	
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



void printBoard(char** board, int rows, int cols){
	cout << endl << "\t";
	for (int i = 1; i < (cols+1); ++i){
		cout << " |"<< i << "|";
	}
	cout << endl << "\t";
	for (int i = 1; i < (cols+1); ++i){
		cout << "----";
	}
	cout << endl << "\t";
	for (int i = 0; i < rows; ++i){
		for (int j = 0; j < cols; ++j){
			cout << " |"<< board[i][j] << "|";
		}
		cout << endl << "\t";
	}
	cout << endl;
} // end of printBoard

/* Ask the player for their move. Specifically, it asks the player for 
the column that the player wishes to drop his piece into and sets the value
 of the lowest row of that column that is not occupied to 'o'. */

void PlayerMove(char** board, int rows, int cols){
	cout << "Select a column: ";
	int choice;
	cin >> choice;
	cin.ignore();
	// make the choice match up with index numbers, not printed numbers
	--choice;

	int count = 0;
	// If choice is valid (within the range of the columns)
	if (choice < cols) {

		// check for empty, up the count 
		for (int i = 0; i < rows; ++i){
			if(board[i][choice] == ' '){
				++count;
			}
		}

		if(-1 < count){
			board[count-1][choice] = 'o';
		}
		else{
			// WHAT DO I DO IF THE COLUMN IS FULL? 
		}
	}
}

void ComputerMove(char** board, int rows, int cols){
	int choice = rand() % cols;

	int count = 0;

	if (choice < cols) {

		// check for empty, up the count 
		for (int i = 0; i < rows; ++i){
			if(board[i][choice] == ' '){
				++count;
			}
		}

		if(-1 < count){
			board[count-1][choice] = 'x';
		}

	}
}

/*
bool checkRow(char** board, int numberConnected){
	int row = 0;
	int col = 0;
	for (int i = 0; i < (numberConnected+2); ++i){
		for (int j = 0; j < (numberConnected+3); ++j){
			if(board[i][j] == 'o'){
				row = i;
				col = j;
			}		
		}
	}

	int count = 0;
	while(count != numberConnected){
		if(board[row][col+count] == 'o'){
			++count;
		}
	}
	if (count == numberConnected){
		return true;
	}
	else{
		return false;
	}
}
*/



void destroyBoard(char** board, int rows){

	// delete the pointers to the arrays 
	for (int i = 0; i < rows; ++i){
		delete board[i];
	}
	delete board;
	board = NULL;

}



// ============================================================= MAIN ======
int main(int argc, char const *argv[]){
	// see the random number generator
	srand(static_cast<unsigned int>(time(NULL)));
	cout << "\tWELCOME TO CONNECT GAME!\n";
	cout << "\tHow many connected pieces are needed to win? \n\t(3,4,5,6): ";
	int numberConnected;
	cin >> numberConnected;
	cin.ignore();

	int rows;
	int cols;

	// set rows and cols for initial gameboard based on number chosen
	switch(numberConnected){
		case 3:
			rows = 5;
			cols = 6;
			break;
		case 4:
			rows = 6;
			cols = 7;
			break;		
		case 5:
			rows = 7;
			cols = 8;
			break;
		case 6:
			rows = 8;
			cols = 9;
			break;
		default:
			cout << "\tIncorrect input.\n";
			exit(1);
	}

	// make the initial board 
	char** board = makeBoard(rows,cols);
	// print the initial board
	printBoard(board, rows, cols);

	// ========================================= gameplay ==============
	// did someone win the game? 
	bool winner = false;

	while (!winner){
		PlayerMove(board, rows, cols);
		printBoard(board, rows, cols);
		ComputerMove(board, rows, cols);
		printBoard(board, rows, cols);
		//checkRow(board,numberConnected);
	}
	destroyBoard(board, rows);
	return 0;
}



























