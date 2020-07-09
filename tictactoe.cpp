//
// Created by karim on 04-Jul-20.
//
#include <cstddef>
#include <iostream>
#include "tictactoe.h"

using namespace std;

board::board() : currentPlayer(false) {
    for (std::size_t i = 0; i != 9; ++i) {
        boardState[i] = ' ';
    }
    width = 22;
    height = 11;
    gameRunningStatus = true;
}

board::board(int preferredWidth, int preferredHeight) {
    for (std::size_t i = 0; i != 9; ++i) {
        boardState[i] = ' ';
    }
    width = preferredWidth;
    height = preferredHeight;
    gameRunningStatus = true;
}

void board::play(int location) {
    if (boardState[location] == ' ') {

        for (std::size_t i = 0; i != 9; ++i) {
            lastBoardState[i] = boardState[i];
        }

        if (currentPlayer == 0)
            boardState[location] = 'x';
        else if (currentPlayer == 1)
            boardState[location] = 'o';

        currentPlayer = !currentPlayer;

    } else {
        cout << "invalid! try again!" << endl;
    }
}

void board::play(char location) {
    if (location == 'e') {
        cout << "Ending game!" << endl;
        gameRunningStatus = false;
    }
    else if (location == 'z') {
        cout << "Undoing last move" << endl;
        for (std::size_t i = 0; i != 9; ++i) {
            boardState[i] = lastBoardState[i];
        }
    }
    else {
        cout << "Invalid! try again!" << endl;
    }
}

void board::printBoard() {

    cout << "enter e to end game, z to undo" << endl;

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
    if (y == height/6) {
        if(x == width/6)
            cout << boardState[0];
        else if (x == width/2)
            cout << boardState[1];
        else if (x == (width - width/5) )
            cout << boardState[2];
    }
    else if (y == height/2) {
        if(x == width/6)
            cout << boardState[3];
        else if (x == width/2)
            cout << boardState[4];
        else if (x == (width - width/5) )
            cout << boardState[5];
    }
    else if (y == (height - height/5)) {
        if(x == width/6)
            cout << boardState[6];
        else if (x == width/2)
            cout << boardState[7];
        else if (x == (width - width/5) )
            cout << boardState[8];
    }
}


