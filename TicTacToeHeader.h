
#pragma once

extern int xBoard;
extern int oBoard;

int getMove(char currPlayer);
void printBoard(int xBoard, int oBoard);
bool placeMark(int moveNumber, int cell);
bool checkWin(int Board);
