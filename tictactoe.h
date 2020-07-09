//
// Created by karim on 04-Jul-20.
//

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H

#include <string>

class board {
private:
    bool currentPlayer;
    char boardState[9];
    int width;
    int height;
    void printCharacter(int x, int y);
    bool gameRunningStatus;
public:
    void play(int location);
    void printBoard();
    board();
    board(int preferredWidth, int preferredHeight);
    bool isOngoing() const {return gameRunningStatus; };
};


#endif //TIC_TAC_TOE_TICTACTOE_H
