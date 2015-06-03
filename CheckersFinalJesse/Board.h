#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include "CheckerNode.h"
#include "Checker.h"
#include "Color.h"

#define NUM_CHECKERS_PER_PLAYER 7
#define MAX_STR_LENGTH 3
#define ROWS 20
#define COLS 20

class Board {
public:
    Board();
    ~Board();
    bool isGameOver();
    void nextTurn();
    Color getWinner();
    void deleteChecker(Color, Checker*);
    void print();
	

private:
    // data
    Color currentTurn;
    Color winner;
    CheckerNode *blackList;
    CheckerNode* redList;
    CheckerNode* orangeList;
    Checker* currentChecker;
    Checker* jumpedChecker;
    int orangeTurnNumber;
    void clearLocation(char,char);

    char board[ROWS][COLS];

    // functions
    void movePiece(const char*,const char*,bool);
    bool isValidMove(const char*,const char*,bool&);
    CheckerNode* getCheckerNodeAt(const char*);
    void deleteNodes(CheckerNode*);
    void asciiToIndices(char, char, int&, int&);

};

#endif // BOARD_H_INCLUDED
