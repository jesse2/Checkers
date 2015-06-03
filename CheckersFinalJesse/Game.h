#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "Board.h"

class Game {

private:
    Board* theGameBoard;

public:
    void playGame();
    void displayInstructions();

};


#endif // GAME_H_INCLUDED
