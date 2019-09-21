#ifndef PLAYERS_H
#define PLAYERS_H

#include "Boards.h"

class Players{
private:
	///Creating an object to access to board class
	Boards* myBoard;
	///String that save player's desire name
	std::string ID;
	///row number for hitting ships
	int row;
	///col char for hitting ships
	char column;
	///bool that to determine whether players are ready to play
	bool allSet;
public:
	/************************************
	 * Constructor/Deconstructor
	 ***********************************/
	 /**
	  *@brief creates the player, which has access to their boards.
	  */
 	Players();
	/**
	 *@brief Frees up any assests the player has from memory.
	 */
	~Players();
	/************************************
	 * Get/Set Functions
	 ***********************************/
	 /**
	  *@pre None.
	  *@brief Grabs both boards to display.
	  */
	void getBoards() const;
	/**
	 *@brief Displays the board from an offensive standpoint.
	 */
	void getOffensiveBoard() const;
	/**
	 *@brief Displays the board from a defensive standpoint.
	 */
	void getDefensiveBoard() const;
	/**
	 *@brief Gets which column the user wants the ship in.
	 */
	void getColumn();
	/**
	 *@brief Gets which row the user wants the ship in.
	 */
	void getRow();
	/**
	 *@pre Number of ships being placed known.
	 *@post All ships are placed on the board.
	 */
	void setShips(int);
	/**
	 *@pre Name desired for the player is given in exec.
	 *@post Name is placed in storage for use by Players.
	 */
	void setID(std::string);
	/**
	 *@brief Returns the player name to the called function.
	 */
	std::string getID();
	/**
	 *@pre Ships are placed on the board.
	 *@post Returns true if a ship is at that location.
	 */
	bool getHit(char, int);

	/************************************
	 * Functions
	 ***********************************/
	/**
	 *@pre None.
	 *@brief If all ships are set, return true.
	 */
    bool shipsSet();
	/**
	 *@brief If the player has no more ships, return true.
	 */
	bool hasLost();
	/**
	 *@brief Marks my board with hits.
	 */
	void markMyHits(char, int);
	/**
	 *@brief Marks my board with misses.
	 */
	void markMyMisses(char, int);
	/**
	 *@brief Marks the opponent's board with hits.
	 */
	void markTheirHits(char, int);
	/**
	 *@brief Marks the opponent's board with misses.
	 */
	void markTheirMisses(char, int);
	/**
	 *@pre Column character is given by user.
	 *@post Character is converted into a numerical value.
	 */
	int charConvert(char);
	/**
	 *@pre Game is finished, and another is wanting to begin.
	 *@post Board is cleaned off.
	 */
	void cleanBoard();
};
#endif
