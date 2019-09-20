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
		/**
		 *@pre Player wants to make their boards.
		 *@post Boards are filled with water and ready to use.
		 */
	Boards();
		/**
		 *@pre Users are done with the game.
		 *@post Memory is freed from allocation.
		 */
	~Boards();
    /****************************************
                    FUNCTIONS
    ****************************************/

	/*
	 * @pre Takes two integers, one for column and one for row
	 * @post returns a boolean value
	 * @note returns true if the position indicated is '~'
	*/
	bool isValid(int, int);
	/*
	 * @pre none
	 * @post none
	 * @note Displays the offensive board for the current Player
  */
	void displayOffensiveBoard() const;
	/*
	 * @pre none
	 * @post none
	 * @note Displays the defensive board for the current Player
	*/
	void displayDefensiveBoard() const;
	/*
	 * @pre none
	 * @post none
	 * @note Displays both the offensive and defensive
	 					boards for the current Player
	*/
	void displayBoth() const;
	/*
	 * @pre Takes two integers, one for column and one for row
	 * @post returns a boolean value
	 * @note returns true if the position indicated is 'S'
	*/
	bool isHit(int, int);
	/*
	 * @pre Takes two integers, one for column and one for row
	 * @post none
	 * @note Marks the array with an 'S' at the specified location
	*/
	void markShips(int, int);
	/*
	 * @pre none
	 * @post Returns a boolean value
	 * @note Returns true if no more 'S' exist in the defensive array
	*/
	bool gameWon();
	/*
	 * @pre Takes two integers, one for column and one for row
	 * @post Returns a character
	 * @note Returns the character located at the specified location
	*/
	char getLocation(int, int);
	/*
	 * @pre Takes two integers, one for column and one for row
	 * @post none
	 * @note Marks the board with either an 'H' if a ship 'S' is found
	 * 		or an 'M' if water '~' is found
	*/
	void boardShot(int, int);
	/*
	 * @pre Takes two integers, one for column and one for row
	 * @post none
	 * @note When the player is shooting marks the hits,
	 * 		on their offensive board if the shot is a hit,
	 * 		marks the specified location with an 'M'
	*/
	void ownBoardHit(int, int);
	/*
	 * @pre Takes two integers, one for column and one for row
	 * @post none
	 * @note When the player is shooting marks the misses,
	 * 		on their offensive board if the shot is a hit,
	 * 		marks the specified location with an 'M'
	*/
	void ownBoardMiss(int, int);
	/*
	 * @pre Takes two integers, one for column and one for row
	 * @post none
	 * @note When the player is being shoot at marks the hits,
	 * 		on their defensive board if the shot is a hit,
	 * 		marks the specified location with an 'M'
	*/
	void otherBoardHit(int, int);
	/*
	 * @pre Takes two integers, one for column and one for row
	 * @post none
	 * @note When the player is being shoot at marks the misses,
	 * 		on their defensive board if the shot is a miss,
	 * 		marks the specified location with an 'M'
	*/
	void otherBoardMiss(int, int);
	/*
	 * @pre Game is over and users want a rematch.
	 * @post Boards are cleaned off.
	 */
	void clearBoards();

};
#endif
