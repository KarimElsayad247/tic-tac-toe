//
// Created by karim on 04-Jul-20.
//

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

#include <string>

class board {
private:
    bool currentPlayer;
    char lastBoardState[9];
    char boardState[9];
    int width;
    int height;
    void printCharacter(int x, int y);
    bool gameRunningStatus;
    bool canUndo;
    void resetBoard();
public:
    void play(int location);
    void play(char location);
    void printBoard();
    board(int preferredWidth = 22, int preferredHeight = 11);
    bool isOngoing() const {return gameRunningStatus; };
};


#endif //TIC_TAC_TOE_TICTACTOE_H
