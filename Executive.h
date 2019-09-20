#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Boards.h"
#include "Players.h"
class Executive{
    private:
        int row, choice;
        char column;
        Players* player1;
        Players* player2;
		      int numberOfShips;
    public:
        /**
        *@pre none
        *@post primary constructor of the Executive class
        *@post returns nothing
        **/
        Executive();
        /**
        *@pre none
        *@post destructor of the Executive class
        *@post returns nothing
        **/
        ~Executive();
        /**
        *@pre none
        *@post none
        *@post Displays the logo for the game
        **/
        void displayLogo();
        /**
        *@pre none
        *@post none
        *@post Displays the menu for the game
        **/
        void displayMenu();
        /**
        *@pre none
        *@post none
        *@post Handles the majority of functionality within
        *     the game. ets players name, calls the setShip
        *     method to begin setting the ships, and handles
        *     swapping turns for each player until the game is won
        **/
        void run();
        /**
        *@pre none
        *@post none
        *@post Prompts the user for a name for player 1
        **/
        void setPlayer1Name();
        /**
        *@pre none
        *@post none
        *@post Prompts the user for a name for player 2
        **/
        void setPlayer2Name();
        /**
        *@pre none
        *@post none
        *@post Returns the name of player 1 for display purposes
        **/
        void getP1Name();
        /**
        *@pre none
        *@post none
        *@post Returns the name of player 2 for display purposes
        **/
        void getP2Name();
        /**
        *@pre none
        *@post none
        *@post Prompts the user to enter the number of ships to be
        *     used during gameplay. Between 1 and 5 ships are allowed
        **/
        void getNumberOfShips();
        /**
        *@pre none
        *@post none
        *@post Repeatedly prmpts the user for a column letter until
        *     a valid column letter is entered
        **/
        void getColumn();
        /**
        *@pre none
        *@post none
        *@post Repeatedly prmpts the user for a row number until
        *     a valid row number is entered
        **/
        void getRow();
};
#endif
