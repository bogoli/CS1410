// board.h
#ifndef BOARD_H
#define BOARD_H

char** makeBoard(int rows, int cols);

void printBoard(char** board, int rows, int cols);

void destroyBoard(char** board, int rows);

#endif

