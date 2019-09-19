/********************************************************
 * @file Boards.h
 * @brief Header file for Boards, manages the playboard.
 */
#ifndef BOARDS_H
#define BOARDS_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

class Boards{
private:
	char myBoard[8][8];
	int rows, cols;
	int numberOfShips;
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
	void displayBoard() const;
	/* @pre None.
	 * @post If the spot is valid to be attacked, true is returned
	 */
	bool isValid(char, int);
	/* @pre Board is filled with water and ships.
	 * @post If guess is a ship, then return true.
	 * @note Turns the ship char into a hit char.
	 */
	bool isHit(char, int);
	/* @pre Board has ships and water.
	 * @post Returns true if it's water, false if it's a ship.
	 */
	bool isPlaceable(char, int);
	/* @pre Board has ships and water.
	 * @post Returns true if all spaces are water in range.
	 * @note Calls isPlaceable over a range of spaces.
	 */
	bool isPlaceableRange(char, char, int, int);
	/* @pre A letter is read in for our guess.
	 * @post Returns the numerical value of the letter.
	 */
	int charConvert(char);
	/* @pre A number is used for checking.
	 * @post Number is changed back into it's letter.
	 */
	char intConvert(int);
	/* @pre Board is filled with ships and water.
	 * @post Board is displayed to screen, but ships are hidden by water.
	 */
	void displayHidden() const;
	/* @pre Board is filled with water, and maybe ships.
	 * @post Board checks for validity on placement and places if possible.
	 */
	void shipCheck(int row1, int row2, char col1, char col2, int size);
	/* @pre Board filled with water.
	 * @post Ship piece placed at given row and col.
	 */
	void placeShip(int row, char col);

	/**
	 * @pre none.
	 * @post Number of ships desired for the game is received from user.
	 */
	void getNumberOfShips();

	/**
	 * @pre none.
	 * @post Game is over when none of ships are left.
	 */
	bool isGameOver();


	/**
	 * @pre Boards are filled.
	 * @post Shot is registered as hit or miss.
	 */
	void checkShot(char X,int Y);


	void FireHit(char column, int row);
	void FireMiss(char column, int row);

};
#endif
