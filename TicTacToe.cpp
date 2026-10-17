#include <bits/stdc++.h>
using namespace std;

int xBoard = 0;
int oBoard = 0;

int getMove(char currPlayer) {
    int cell = 0;
    while (true) {
        cout << currPlayer << "'s Turn. Enter a number between 0 to 8: " << endl;

        if (cin >> cell && cell > -1 && cell < 9) {
            return cell;
        } 
        else cout << "Invalid. Try again" << endl;

        cin.clear();
    }
}

void printBoard(int xBoard, int oBoard) {
    for(int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int currCell = i*3 + j;
            
            if (xBoard&(1<<currCell)) {
                        cout << "X ";
            } 
            else if (oBoard&(1<<currCell)) {
                        cout << "O ";
            } 
            else cout << ". ";
        }
        cout << endl;  
    }
    return;
}

bool placeMark(int moveNumber, int cell) {
    if((xBoard|oBoard)&(1<<cell)) {
        return false; 
    }

    if(moveNumber%2 == 1) {
        oBoard = oBoard | (1<<cell);
    } 
    else {
        xBoard = xBoard | (1<<cell);
    }
    return true;
}

bool checkWin(int Board) {
    int winMasks[8] = {
        ((1<<0)|(1<<1)|(1<<2)),
        ((1<<3)|(1<<4)|(1<<5)),
        ((1<<6)|(1<<7)|(1<<8)),
        ((1<<0)|(1<<3)|(1<<6)),
        ((1<<1)|(1<<4)|(1<<7)),
        ((1<<2)|(1<<5)|(1<<8)),
        ((1<<2)|(1<<4)|(1<<6)),
        ((1<<0)|(1<<4)|(1<<8))
    };

    for (int i = 0; i < 8; i++) {
        if((winMasks[i]&Board) == winMasks[i]) {
            return true;
        }
    }
    return false;
}
int main() {
    char player1 = 'X';
    char player2 = 'O';
    char currPlayer = player1;
    int moveNumber = 0;

    cout << "0 1 2" << endl << "3 4 5" << endl << "6 7 8" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "This is a Tic-Tac-Toe game built differently but the way to play is still the same." << endl;
    cout << "First move is by X and then the game will teach u along the way." << endl;
    cout << "The grid that has been printed above shows you the the cell indices. Enter that number to fill that cell." << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;
    cout << "---------------------------------------------------------------------------------------------------------" << endl;

    printBoard(xBoard, oBoard);

    while (moveNumber < 9) {
        if (moveNumber%2 == 0) {
            currPlayer = player1;
        } 
        else currPlayer = player2;

        int cell = getMove(currPlayer);

        if (!placeMark(moveNumber, cell)) {
            cout << "firse try karo." << endl;
            continue;
        }

        printBoard(xBoard, oBoard);

        if(checkWin(xBoard)) {
            cout << "X has won!";
            break;
        } 
        else if (checkWin(oBoard)) {
            cout << "O has won!";
            break;
        }
        moveNumber++;
    }
    
    if (checkWin(xBoard) == false && checkWin(oBoard) == false) {
        cout << "Draw. LOL" << endl;
    }
    return 0;
}