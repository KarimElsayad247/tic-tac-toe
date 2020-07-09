#include <iostream>
#include "tictactoe.h"

using namespace std;

int main() {
    board currentGame;

    while (currentGame.isOngoing()) {
        currentGame.printBoard();
        cout << "Enter location [0-8]: ";
        int location;
        cin >> location;
        currentGame.play(location);
    }
}
