#ifndef BLACKCHECKER_H_INCLUDED
#define BLACKCHECKER_H_INCLUDED

#include "Checker.h"

class BlackChecker : public Checker {

public:
    BlackChecker(const char*, Color);
    bool destruct(int);
    bool isValidMove(const char*, bool&);
private:
	bool power;
};


#endif // BLACKCHECKER_H_INCLUDED
