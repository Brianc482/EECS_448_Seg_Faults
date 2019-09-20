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
	/**
	 *@pre none
	 *@post none
	 *@note Displays the offensive board for the current Player
   */
	void displayOffensiveBoard() const;
	/**
	 *@pre none
	 *@post none
	 *@note Displays the defensive board for the current Player
   */
	void displayDefensiveBoard() const;
	/**
	 *@pre none
	 *@post none
	 *@note Displays both boards for the current Player.
	 */
	void displayBoth() const;
	/**
	 *@pre Board is ready to have ships placed on it.
	 *@post Returns true if space given is water.
	 */
	bool isValid(int, int);
	/**
	 *@pre Board has ships on it, and the game is in action.
	 *@post Returns true if space given is a ship.
	 */
	bool isHit(int, int);
	/**
	 *@pre Ships are being placed.
	 *@post After ship is placed, displays the board to the player.
	 */
	void markShips(int, int);
	/**
	 *@brief Adds a hit to your board.
	 */
	void ownBoardHit(int, int);
	/**
	 *@brief Adds a miss to your board.
	 */
	void ownBoardMiss(int, int);
	/**
	 *@brief Adds a hit to your opponent's board.
	 */
	void otherBoardHit(int, int);
	/**
	 *@brief Adds a miss to your opponent's board.
	 */
	void otherBoardMiss(int, int);
	/**
	 *@pre Game is being played.
	 *@post If no ships remain, game is over.
	 */
	bool gameWon();
	/**
	 *@brief Returns what character is at the given position.
	 */
	char getLocation(int, int);
	/**
	 *@brief Shoots your shot at the opponent's board.
	 */
	void boardShot(int, int);
};
#endif
