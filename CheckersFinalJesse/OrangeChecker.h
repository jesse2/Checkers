#ifndef ORANGECHECKER_H_INCLUDED
#define ORANGECHECKER_H_INCLUDED

#include "Checker.h"

class OrangeChecker : public Checker{
public:
	bool hasPower();
	void removePower();
    OrangeChecker(const char*, Color);
    bool isValidMove(const char*, bool&);
private:
	bool power;
};


#endif // ORANGECHECKER_H_INCLUDED
