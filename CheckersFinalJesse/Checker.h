#ifndef CHECKER_H_INCLUDED
#define CHECKER_H_INCLUDED

#include "Color.h"

class Checker {

protected:
    char row;
    char col;
    bool kinged;
    Color color;

public:
    Checker(const char*, Color);
    void setLocation(const char*);
    void king();
    bool isKing();
    virtual bool isValidMove(const char*, bool&) = 0;
    char getRow();
    char getCol();
    Color getColor();
    bool equals(const char*);
};

#endif // CHECKER_H_INCLUDED
