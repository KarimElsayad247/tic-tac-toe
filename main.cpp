#include <iostream>
#include "tictactoe.h"

using namespace std;

int main() {
    board currentGame;
    const char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    while (currentGame.isOngoing()) {
        currentGame.printBoard();
        cout << "Enter location [0-8]: ";
        char location;
        cin >> location;

        if ( (location - '0') < 9) {
            currentGame.play((int)(location-'0'));
        } else {
            currentGame.play(location);
        }
    }
}
