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
        *@pre takes a string for the filename
        *@post run determines which mode to run the program in
        *@post returns nothing
        **/
        void run();
        void displayMenu();
        void getNumberOfShips();
        void getRow();
        void getColumn();
        void setPlayer1Name();
        void setPlayer2Name();
        void getP1Name();
        void getP2Name();
};
#endif
