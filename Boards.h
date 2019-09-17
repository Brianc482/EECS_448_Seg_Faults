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
	 */
	void displayOffensiveBoard() const;
	void displayDefensiveBoard() const;
	void displayBoth() const;
	/* @pre None.
	 * @post If the spot is valid to be attacked, true is returned
	 */
	bool isValid(char, int);
	/* @pre Board is filled with water and ships.
	 * @post If guess is a ship, then return true.
	 * @note Turns the ship char into a hit char.
	 */
	bool isHit(char, int);
	/* @pre A letter is read in for our guess.
	 * @post Returns the numerical value of the letter.
	 */
	int charConvert(char);
	/* @pre Board is filled with ships and water.
	 * @post Board is displayed to screen, but ships are hidden by water.
	 */
	void displayHidden() const;
};
#endif
