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
	char** myBoard;
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
	void displayBoard(bool personal) const;


};
#endif
