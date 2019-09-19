#ifndef PLAYERS_H
#define PLAYERS_H

#include "Boards.h"

class Players{
private:
	Boards* myBoard;
	std::string ID;
	int row;
	char column;
	bool allSet;
public:
	/************************************
	 * Constructor/Deconstructor
	 ***********************************/
 	Players();
	~Players();
	/************************************
	 * Get/Set Functions
	 ***********************************/
	void getBoards() const;
	void getOffensiveBoard() const;
	void getDefensiveBoard() const;
	void getColumn();
	void getRow();
	void setShips(int);
	void setID(std::string);
	std::string getID();
	bool getHit(char, int);

	/************************************
	 * Functions
	 ***********************************/
  bool shipsSet();
	bool hasLost();
	void markHits(char, int);
	void markMisses(char, int);
	int charConvert(char);
};
#endif
