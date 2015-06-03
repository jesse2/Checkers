#include "Game.h"
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;
void menu();
void menu_selection(char option);
void menu(){

	cout<< "Menu Options"<<endl
		<<"-----------------------------------------------"<<endl
		<<"p: Play"<<endl
		<<"q: Quit"<<endl
		<<"Please enter p to play or q to quit: "<<ends;
	
}
void menu_selection(char option)
{
	switch(option)
	{
	case 'p':
		 Game myGame;
    myGame.displayInstructions();
    myGame.playGame();
		break;

	case 'q':
		// main loop will take care of this.
		break;

	default:
		cout<<"Error: Invalid Input.  Please try again...\n"<<endl;
		break;
	}
}
int main() {
	char input_buffer;
	cout<<"Welcome to Team Binary's 3 player checker game!\n"<<endl;
	do
	{
		menu();

		input_buffer = tolower(getchar()); 
		cin.ignore();
		menu_selection(input_buffer);
	} 
	while (input_buffer != 'q');

    return 0;
}
