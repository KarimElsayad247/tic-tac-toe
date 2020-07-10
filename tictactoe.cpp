//
// Created by karim on 04-Jul-20.
//
#include <cstddef>
#include <iostream>
#include "tictactoe.h"

using namespace std;

// setting up the game board with preferred width and height, otherwise default arguments are used.
// all spots are numbered
board::board(int preferredWidth, int preferredHeight) {
    const char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (std::size_t i = 0; i != 9; ++i) {
        boardState[i] = digits[i];
    }
    width = preferredWidth;
    height = preferredHeight;
    gameRunningStatus = true;
    canUndo = false;
    currentPlayer = 0;
}

// writes x or o depending on current player in the location provided
void board::play(int location) {
    // player can't overwrite an already used spot
    // unused spots are marked with a digit
    if (isdigit(boardState[location])) {

        // can undo after at least: 1 move
        // - from game start
        // - after last undo
        canUndo = true;

        // save current board state for undo
        for (std::size_t i = 0; i != 9; ++i) {
            lastBoardState[i] = boardState[i];
        }

        // update board state with provided input
        if (currentPlayer == 0)
            boardState[location] = 'x';
        else if (currentPlayer == 1)
            boardState[location] = 'o';

        // change players
        currentPlayer = !currentPlayer;

    } else {
        cout << "invalid! try again!" << endl;
    }
}

// exit and undo
void board::play(char location) {

    if (location == 'e') {
        cout << "Ending game!" << endl;
        gameRunningStatus = false;
    }
    else if (location == 'z') {
        // players can only undo one move
        if (canUndo) {
            cout << "Undoing last move" << endl;
            for (std::size_t i = 0; i != 9; ++i) {
                boardState[i] = lastBoardState[i];
                canUndo = false;
            }
        } else {
            cout << "can't undo!" << endl;
        }
    }
    else if (location == 'r') {
        resetBoard();
    }
    else {
        cout << "Invalid! try again!" << endl;
    }
}

// prints the board
void board::printBoard() {

    cout << "enter e to end game, z to undo, r to reset board to initial state" << endl;

    static string horizontalBorder(width, '-');
    static string horizontalBlank= string(width/3, ' ') + "|" +
                                   string(width/3, ' ') + "|" +
                                   string(width/3, ' ');

    static string horizontalMidLine = string(width/3, '-') + "|" +
                                      string(width/3, '-') + "|" +
                                      string(width/3, '-');
    // output top line
    cout << horizontalBlank << endl;

    for (int y = 1; y != height -1 ; ++y) {
        for (int x = 0; x != width; ++x) {
            // if line with x or o
            if (y == (height - height/5) || y == height/2 || y == height/6) {
                // position is for x or o
                if (x == (width - width/5) || x == width/2 || x == width/6) {
                    printCharacter(x, y);
                }
                // if spot with vertical border filling (midLine)
                else if (x == (width/2 - width/5) || x == (width/2 + width/5)) {
                    cout << "|";
                }
                // otherwise, it's a blank spot
                else {
                    cout << " ";
                }
            }
            // if line with horizontal border filling (midLine)
            else if (y == (height/2 - height/5) || y == (height/2 + height/5)) {
                cout << horizontalMidLine;
                break;
            }
            // otherwise, it's a blank line
            else {
                cout << horizontalBlank;
                break;
            }
        }
        cout << endl;
    }

    // output bottom blank
    cout << horizontalBlank << endl;
}

void board::printCharacter(int x, int y) {
    if (y == height/6) {    // top line
        if(x == width/6)
            cout << boardState[0];
        else if (x == width/2)
            cout << boardState[1];
        else if (x == (width - width/5) )
            cout << boardState[2];
    }
    else if (y == height/2) { // middle line
        if(x == width/6)
            cout << boardState[3];
        else if (x == width/2)
            cout << boardState[4];
        else if (x == (width - width/5) )
            cout << boardState[5];
    }
    else if (y == (height - height/5)) {    // bottom line
        if(x == width/6)
            cout << boardState[6];
        else if (x == width/2)
            cout << boardState[7];
        else if (x == (width - width/5) )
            cout << boardState[8];
    }
}

void board::resetBoard() {
    const char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (std::size_t i = 0; i != 9; ++i) {
        boardState[i] = digits[i];
    }
}


