#ifndef REDCHECKER_H_INCLUDED
#define REDCHECKER_H_INCLUDED

#include "Checker.h"

class RedChecker : public Checker{
public:
    RedChecker(const char*, Color);
    bool hasShield();
    void removeShield();
    bool isValidMove(const char*, bool&);
private:
    bool shield;

};


#endif // REDCHECKER_H_INCLUDED
