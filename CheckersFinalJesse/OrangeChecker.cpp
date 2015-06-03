#include "OrangeChecker.h"

OrangeChecker::OrangeChecker(const char* loc, Color inColor) : Checker(loc, inColor) {
    // do nothing
}
bool OrangeChecker::hasPower(){
    return power;

}

void OrangeChecker::removePower(){
    power = false;

}
bool OrangeChecker::isValidMove(const char* pos, bool &isJump)
{
    char inRow = pos[1];
    char inCol = pos[0];
	if(kinged)
	{
		if(((row+2==inRow || row-2==inRow)&&(col+2==inCol || col-2==inCol))||(row==inRow && (col+2==inCol || col-2==inCol))||(col==inCol && (row+2==inRow || row-2==inRow)))
		{	
			isJump=true;
			return true;
		}
		else if(((row+1==inRow || row-1==inRow)&&(col+1==inCol || col-1==inCol)) || (row==inRow && (col+1==inCol || col-1==inCol))||(col==inCol && (row+1==inRow || row-1==inRow)))
		{
			isJump=false;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		if((col+1==inCol &&(inRow == row-1 || inRow == row +1)))
		{
			isJump=false;
			return true;
		}
		else if(col+2==inCol &&(inRow == row-2 || inRow == row +2))
		{
			isJump=true;  
			return true;
		}
		else
		{
			return false;
		}

	}
}
