#include <stdio.h>
#include <iostream>
#include <string.h>
#include <ctype.h>

#include "Game.h"
#include "Color.h"

using namespace std;

void Game::displayInstructions(){
    printf("%s", "This game will have 3 players: Red, Black and Orange.\n");
    printf("%s", "Order of play will be clockwise beginning with Red, then Black and then Orange.\n");
    printf("%s", "To move, enter starting coordinate of piece to move, then ending coordinate of\npiece to move.\n");

}

void Game::playGame(){

        theGameBoard = new Board();
        while(!theGameBoard->isGameOver()){
            theGameBoard->nextTurn();
            theGameBoard->print();

        }
        

        if(theGameBoard->getWinner() == RED){
            printf("%s", "The winner is Red!\n");
        }
        else if(theGameBoard->getWinner() == BLACK){
            printf("%s", "The winner is Black!\n");
        }
        else if(theGameBoard->getWinner() == ORANGE){
            printf("%s", "The winner is Orange!\n");
        }
		delete(theGameBoard);
}

