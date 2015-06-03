#include <cstdlib>
#include "BlackChecker.h"

BlackChecker::BlackChecker(const char* loc, Color inColor) : Checker(loc, inColor) {
    // do nothing
}

bool BlackChecker::destruct(int x)
{
	srand(x);
	int random;
	random=(rand() % 10)+1;
	if(random<5)
	{
        power=false;
    }
    else
	{
        power=true;
    }
	return power;
}

bool BlackChecker::isValidMove(const char* pos, bool &isJump){
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
		if(inRow == row-2 && (inCol == col-2 || inCol == col +2))
			{
				isJump=true;
				return true;
			 }
		if(inRow == row-1 &&(inCol == col-1 || inCol == col +1))
		{
			isJump=false;	 
			return true;
		}
		else
		{
			return false;
		}

	}
}
