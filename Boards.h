/********************************************************
 * @file Boards.h
 * @brief Header file for Boards, manages the playboard.
 */
#ifndef BOARDS_H
#define BOARDS_H

#include <iostream>
#include <string>

class Boards{
private:
	char offensiveBoard[8][8];
	char defensiveBoard[8][8];
	int rows, cols;
public:
    /****************************************
            CONSTRUCTOR/DECONSTRUCTOR
    ****************************************/
	Boards();
	~Boards();
    /****************************************
                    FUNCTIONS
    ****************************************/
	/* @pre none
	 * @post none
	 * @note Displays the offensive board for the current Player
    */
	void displayOffensiveBoard() const;
	void displayDefensiveBoard() const;
	void displayBoth() const;
	bool isValid(int, int);
	bool isHit(int, int);
	void markShips(int, int);
	void boardHit(int, int);
	void boardMiss(int, int);
	bool gameWon();
	char getLocation(int, int);
	void boardShot(int, int);
};
#endif
