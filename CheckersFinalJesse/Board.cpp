#include <iostream>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include "Board.h"
#include "Checker.h"
#include "Color.h"
#include "BlackChecker.h"
#include "RedChecker.h"
#include "OrangeChecker.h"
using namespace std;

Board::Board(){
	//initializes all linked lists
	redList=new CheckerNode("B1", RED);
	redList->next=new CheckerNode("C2", RED);
	redList->next->next=new CheckerNode("D1", RED);
	redList->next->next->next=new CheckerNode("E2", RED);
	redList->next->next->next->next=new CheckerNode("F1", RED);
	redList->next->next->next->next->next=new CheckerNode("G2", RED);
	redList->next->next->next->next->next->next=new CheckerNode("H1", RED);

	blackList=new CheckerNode("B9", BLACK);
	blackList->next=new CheckerNode("C8", BLACK);
	blackList->next->next=new CheckerNode("D9", BLACK);
	blackList->next->next->next=new CheckerNode("E8", BLACK);
	blackList->next->next->next->next=new CheckerNode("F9", BLACK);
	blackList->next->next->next->next->next=new CheckerNode("G8", BLACK);
	blackList->next->next->next->next->next->next=new CheckerNode("H9", BLACK);

	orangeList=new CheckerNode("A2", ORANGE);
	orangeList->next=new CheckerNode("B3", ORANGE);
	orangeList->next->next=new CheckerNode("A4", ORANGE);
	orangeList->next->next->next=new CheckerNode("B5", ORANGE);
	orangeList->next->next->next->next=new CheckerNode("A6", ORANGE);
	orangeList->next->next->next->next->next=new CheckerNode("B7", ORANGE);
	orangeList->next->next->next->next->next->next=new CheckerNode("A8", ORANGE);

	//set everything to initial settings
	currentTurn    = RED;
	currentChecker = NULL;
	jumpedChecker  = NULL;
	int x, y;
	orangeTurnNumber = 1;

   char temp[20][20] =         {{' ','A',' ','B',' ','C',' ','D',' ','E',' ','F',' ','G',' ','H',' ','I',' ',' '},
                               {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
						       {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','1'},
						       {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
						       {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','2'},
						       {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
						       {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','3'},
						       {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
						       {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','4'},
                               {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
                               {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','5'},
                               {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
                               {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','6'},
						       {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
                               {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','7'},
                               {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
						       {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','8'},
						       {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '},
						       {'#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#',' ','#','9'},
						       {'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',' '}};
   					     
	for (y = 0; y < ROWS; y++) 
	{
		for (x = 0; x < COLS; x++)
			{	
				board[y][x] = temp[y][x];
			}
	}
    print();
}

Board::~Board()
{
	if(redList!=NULL)
	{
		deleteNodes(redList);
	}
	if(blackList!=NULL)
	{
		deleteNodes(blackList);
	}
	if(orangeList!=NULL)
	{
		deleteNodes(orangeList);
	}
}

void Board::deleteNodes(CheckerNode* node) //does this need void or anything in front of it to run?
{
    if(node->next!=NULL) {
        deleteNodes(node->next);
    }

    if(node != NULL) {
        delete(node);
    }

}

bool Board::isGameOver()
{
	if(redList==NULL && blackList==NULL && orangeList!=NULL)
	{
		winner = ORANGE;
		return true;
	}
	else if(orangeList==NULL && blackList==NULL && redList!=NULL)
	{
		winner = RED;
		return true;
	}
	else if(redList==NULL && orangeList==NULL && blackList!=NULL)
	{
		winner = BLACK;
		return true;
	}
	else
	{
		return false;
	}
}

void Board::nextTurn()
{
	char start[MAX_STR_LENGTH];
	char dest[MAX_STR_LENGTH];
	char middle[MAX_STR_LENGTH];
	char orangeTurn[MAX_STR_LENGTH];
	CheckerNode* tempNode;

	if(currentTurn == RED)
        printf("RED ");
    else if(currentTurn == BLACK)
        printf("BLACK ");
    else
        printf("ORANGE ");

	printf("Please enter the coordinate of the piece you would like to move.\n");
	cin.getline(start, MAX_STR_LENGTH);
	start[0] = toupper(start[0]);

	printf("Please enter the coordinate of where you would like to move the piece.\n");
	cin.getline(dest, MAX_STR_LENGTH);
	dest[0] = toupper(dest[0]);

	bool isJump;
	tempNode = getCheckerNodeAt(start);
	if(tempNode != NULL)
        currentChecker = tempNode->checker;

	bool isValid = isValidMove(start, dest, isJump);

	if(isValid)
	{
		if(isJump)
		{
			middle[0] = (dest[0] + start[0])/2;
			middle[1] = (dest[1] + start[1])/2;
			jumpedChecker = getCheckerNodeAt(middle)->checker;
		}
		else
		{
			jumpedChecker = NULL;
		}

		movePiece(start, dest, isJump);

		// update currentTurn to the next player's turn
		if(currentTurn==BLACK)
		{
		    // handle where player is eliminated
		    if(orangeList != NULL) {
                currentTurn=ORANGE;
                orangeTurnNumber = 1;
		    }
		    else {
		        currentTurn = RED;
		    }
		}
		else if(currentTurn==RED)
		{
		    // handle where player is eliminated
		    if(blackList != NULL)
                currentTurn=BLACK;
            else
                currentTurn = ORANGE;
		}
		else
		{
			OrangeChecker* tempOrange = dynamic_cast<OrangeChecker*>(currentChecker);
			if(tempOrange->hasPower()){
			if(orangeTurnNumber==1)
			{
				print();
				printf("would you like to go again? Y/N\n");
				cin.getline(orangeTurn, MAX_STR_LENGTH-1);
				if(orangeTurn[0]=='Y' || orangeTurn[0]=='y')//might be able to use strcmp function
				{
					orangeTurnNumber++;
					tempOrange->removePower();
					nextTurn();
				}

			}
			}
			// handle where the player is eliminated
			if(redList != NULL)
                currentTurn = RED;
            else
                currentTurn = BLACK;
		}
	}
	else
	{
		printf("Move is invalid. Please make a valid move.\n");
		nextTurn();
	}
}

Color Board::getWinner()
{
	return winner;
}

void Board::asciiToIndices(char asciiRow, char asciiCol, int& tempRow, int& tempCol)
{
	switch(asciiRow)
	{
        case '1': tempRow=2; break;
        case '2': tempRow=4; break;
        case '3': tempRow=6; break;
        case '4': tempRow=8; break;
        case '5': tempRow=10; break;
        case '6': tempRow=12; break;
        case '7': tempRow=14; break;
        case '8': tempRow=16; break;
        case '9': tempRow=18; break;
        default: ;// TODO throw an exception here
	}

	switch(asciiCol)
	{
        case 'A': tempCol=1; break;
        case 'B': tempCol=3; break;
        case 'C': tempCol=5; break;
        case 'D': tempCol=7; break;
        case 'E': tempCol=9; break;
        case 'F': tempCol=11; break;
        case 'G': tempCol=13; break;
        case 'H': tempCol=15; break;
        case 'I': tempCol=17; break;
        default: ;// TODO: throw an exception here
	}
}

void Board::print()//take close look at method idk if this will work
{
	char asciiRow;
	char asciiCol;
	int row;
	int col;
	bool isKing;
	CheckerNode* tempNode = blackList;

    while(tempNode != NULL)
    {
        asciiRow=tempNode->checker->getRow();
        asciiCol=tempNode->checker->getCol();
        asciiToIndices(asciiRow,asciiCol, row, col);

        isKing = tempNode->checker->isKing();
        if(isKing)
            board[row][col]='B';
        else
            board[row][col]='b';

        tempNode = tempNode->next;
    }

	tempNode = redList;

    while(tempNode != NULL)
    {
        asciiRow=tempNode->checker->getRow();
        asciiCol=tempNode->checker->getCol();
        asciiToIndices(asciiRow,asciiCol, row, col);

        isKing = tempNode->checker->isKing();
        if(isKing)
            board[row][col]='R';
        else
            board[row][col]='r';

        tempNode = tempNode->next;
    }

	tempNode = orangeList;

    while(tempNode != NULL)
    {
        asciiRow=tempNode->checker->getRow();
        asciiCol=tempNode->checker->getCol();
        asciiToIndices(asciiRow,asciiCol, row, col);

        isKing = tempNode->checker->isKing();
        if(isKing)
            board[row][col]='O';
        else
            board[row][col]='o';

        tempNode = tempNode->next;
    }

	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			std::cout << board[i][j];
		}
		std::cout << std::endl;
	}
}

bool Board::isValidMove(const char *start,const char *dest, bool &isJump)
{
    char startRow = start[1];
    char startCol = start[0];
    char endRow = dest[1];
    char endCol = dest[0];


	char middlePiece;

	char asciiRow;
	asciiRow= (dest[1] + start[1])/2;
	char asciiCol;

	asciiCol= (dest[0] + start[0])/2;
	int row;
	int col;
	asciiToIndices(asciiRow, asciiCol, row, col);
	middlePiece=board[row][col];

	

    bool isValid = false;
    CheckerNode* curNode;

    static char orangeLastMove[3];

    // make sure the user selected a square with a checker to start with
    if(currentChecker == NULL) {
        printf("No checker at start loc\n");
        return false;
    }


    //Make sure start containes a checker of the current player's color
    if(!(currentChecker->getColor() == currentTurn)) {
        printf("Selected checker not of your color\n");
        return false;
    }


    //Make sure end is unoccupied
    curNode = getCheckerNodeAt(dest);
    if(curNode != NULL) {
        printf("Checker already on ending square\n");
        return false;
    }

    // make sure dest is within bounds of the board
    if(endCol < 'A' || endCol > 'I' || endRow < '1' || endRow > '9') {
        printf("End outside bounds of board\n");
        return false;
    }

    //if orange's turn.....
    if(currentTurn == ORANGE && orangeTurnNumber == 2)
    {
        if(!(start[0] == orangeLastMove[0] && start[1] == orangeLastMove[1]))
        {
            printf("Orange must move same checker on 2nd turn\n");
            isJump = false;
            return false;

        }
    }
	isValid=currentChecker->isValidMove(dest,isJump);

		if(isJump==true)
		{
			char middle[MAX_STR_LENGTH-1];
			middle[0] = (dest[0] + start[0])/2;
			middle[1] = (dest[1] + start[1])/2;
			jumpedChecker = getCheckerNodeAt(middle)->checker;
			if(middlePiece!=' '&& jumpedChecker->getColor()!=currentChecker->getColor())
			{
				isValid=true;
			}
			else
			{
				isValid=false;
			}
		}

    if(isValid) {
        orangeLastMove[0] = dest[0];
        orangeLastMove[1] = dest[1];
    }

    return isValid;
}

void Board::clearLocation(char inRow, char inCol) {
    int tempRow;
    int tempCol;
    asciiToIndices(inRow, inCol, tempRow, tempCol);
    board[tempRow][tempCol] = ' ';
}

void Board::movePiece(const char *start,const char *dest,bool isJump)
{
    char endRow = dest[1];
    char endCol = dest[0];

	//remove the piece from its old location
	char startrow=start[1];
	char startcol=start[0];
	clearLocation(startrow, startcol);

    //update piece to its new location
    currentChecker->setLocation(dest);

    if(isJump == true)
    {
        if(jumpedChecker->getColor() == BLACK)
        {
            BlackChecker* tempBlack = dynamic_cast<BlackChecker*>(jumpedChecker);
            if(tempBlack->destruct(time(NULL)) == true)
            {
             //delete black piece and piece jumping
             printf("BANG! Black checker exploded also deleting the jumping checker\n");
			 if(currentChecker->getColor()==ORANGE)
			 {
				 OrangeChecker* tempOrange = dynamic_cast<OrangeChecker*>(currentChecker);
				 tempOrange->removePower();
			}
             deleteChecker(currentChecker->getColor(), currentChecker);
            }
            deleteChecker(jumpedChecker->getColor(), jumpedChecker);

        }
        else if(jumpedChecker->getColor() == RED)
        {
            RedChecker* tempRed = dynamic_cast<RedChecker*>(jumpedChecker);
            if(tempRed->hasShield())
            {
                printf("RED was jumped but had a shield!\n");
                tempRed->removeShield();
            }
            else
            {
                //remove piece being jumped
                deleteChecker(jumpedChecker->getColor(), jumpedChecker);
            }

        }
        else
        {
         //remove piece being jumped
         deleteChecker(jumpedChecker->getColor(), jumpedChecker);
        }
    } // end isJump == true

    if(currentChecker->getColor() == RED && endRow == '9')
    {
        currentChecker->king();
    }

    if(currentChecker->getColor() == BLACK && endRow == '1')
    {
        currentChecker->king();
    }

    if(currentChecker->getColor() == ORANGE && endCol    == 'I')
    {
        currentChecker->king();
    }
}

void Board::deleteChecker(Color aColor, Checker* aChecker)
{
    CheckerNode* myList;
    CheckerNode* prev;
    CheckerNode* cur;
    if(aColor == RED)
    {
        myList = redList;
    }
    else if(aColor == ORANGE)
    {
        myList = orangeList;
    }
    else if(aColor == BLACK)
    {
        myList = blackList;
    }
    else{
        myList = NULL;
        // TODO throw an error
    }

    prev = NULL;
    cur = myList;

    while(cur != NULL)
    {
        if((cur->checker->getRow() == aChecker->getRow()) &&
           (cur->checker->getCol() == aChecker->getCol()))
        {
            if(prev == NULL)
            {
                myList = cur->next;
                // if we have removed the first element of the linked list we also need to update the head
                if(aColor == RED)
                    redList = myList;
                else if(aColor == ORANGE)
                    orangeList = myList;
                else
                    blackList = myList;
                clearLocation(cur->checker->getRow(), cur->checker->getCol());
                delete(cur);
                break;
            }
            else
            {
                prev->next = cur->next;
                clearLocation(cur->checker->getRow(), cur->checker->getCol());
                delete(cur);
                break;
            }
        }

        prev = cur;
        cur = cur->next;
    }
}


CheckerNode* Board::getCheckerNodeAt(const char* loc)
{
    // loop through each linked list
    // if the node's checker's location matches loc, return this checkerNode
    CheckerNode* temp = redList;
    while(temp != NULL)
    {
        if(temp->checker->equals(loc))
            return temp;

        temp = temp->next;
    }

    temp = blackList;

    while(temp != NULL)
    {
        if(temp->checker->equals(loc))
            return temp;

        temp = temp->next;
    }

    temp = orangeList;

    while(temp != NULL)
    {
        if(temp->checker->equals(loc))
            return temp;

        temp = temp->next;
    }

    // if not found return null
    return NULL;
}

