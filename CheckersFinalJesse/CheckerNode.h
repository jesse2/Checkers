#ifndef CHECKERNODE_H_INCLUDED
#define CHECKERNODE_H_INCLUDED

#include "Checker.h"

class CheckerNode{
public:
    CheckerNode(const char*, Color);
    Checker* checker;
    CheckerNode* next;
};


#endif // CHECKERNODE_H_INCLUDED
