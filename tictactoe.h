//
// Created by karim on 04-Jul-20.
//

#ifndef TIC_TAC_TOE_BOARD_H
#define TIC_TAC_TOE_BOARD_H

#include <string>

class board {
private:
    bool currentPlayer;

public:
    void play(int location);
    std::string printBoard();
};


#endif //TIC_TAC_TOE_BOARD_H
