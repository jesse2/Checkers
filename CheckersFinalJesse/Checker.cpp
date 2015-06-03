#include <stdio.h>
#include <iostream>
#include "Checker.h"

Checker::Checker(const char* pos, Color inColor){
    kinged = false;
    setLocation(pos);
    color = inColor;
}
void Checker::setLocation(const char* pos){
    col = pos[0];
    row = pos[1];

}

bool Checker::isKing(){
    return kinged;
}

void Checker::king(){
    kinged = true;
}

char Checker::getRow() {
    return row;
}

char Checker::getCol() {
    return col;
}

Color Checker::getColor() {
    return color;
}

bool Checker::equals(const char* loc) {
    if(col == loc[0] && row == loc[1])
        return true;
    else
        return false;
}
