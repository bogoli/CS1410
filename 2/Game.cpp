// game.cpp

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


void RunGame(){
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


}