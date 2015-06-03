#include <cstdio>
#include "CheckerNode.h"
#include "RedChecker.h"
#include "BlackChecker.h"
#include "OrangeChecker.h"

CheckerNode::CheckerNode(const char* pos, Color inColor) {
    if(inColor == RED) {
        checker = new RedChecker(pos, inColor);
    }
    else if(inColor == BLACK) {
        checker = new BlackChecker(pos, inColor);
    }
    else if(inColor == ORANGE) {
        checker = new OrangeChecker(pos, inColor);
    }
    else {
        // TODO throw exception
    }
    next = (CheckerNode*)NULL;
}
