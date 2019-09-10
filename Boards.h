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
	/* @pre Board is kept safe in myBoard.
	 * @post Board is displayed on screen.
	 * @note Personal is for confidentiality if viewing the other's board.
	 */
	void displayOffensiveBoard() const;
	void displayDefensiveBoard() const;
	void displayBoth() const;
	bool isValid(char, int);
	bool isHit(char, int);
	int charConvert(char);
};
#endif
