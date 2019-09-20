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
        /**
         *@pre Game has just been opened.
         *@post Game starts, or program closes.
         */
        void displayMenu();
        /**************************************
         * Get/Set Functions
         *************************************/
        /**
         *@brief Gets the number of ships desired from the user.
         */
        void getNumberOfShips();
        /**
         *@brief User enters the row to attack.
         */
        void getRow();
        /**
         *@brief User enters the column to attack.
         */
        void getColumn();
        /**
         *@brief User 1 sets their name.
         */
        void setPlayer1Name();
        /**
         *@brief User 2 sets their name.
         */
        void setPlayer2Name();
        /**
         *@brief Returns User 1's name.
         */
        void getP1Name();
        /**
         *@brief Returns User 2's name.
         */
        void getP2Name();
};
#endif
