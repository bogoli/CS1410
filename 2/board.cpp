// board.cpp 


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



void destroyBoard(char** board, int rows){

	// delete the pointers to the arrays 
	for (int i = 0; i < rows; ++i){
		delete board[i];
	}
	delete board;
	board = NULL;

}
