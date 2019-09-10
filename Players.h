#ifndef PLAYERS_H
#define PLAYERS_H

#include "Boards.h"

class Players{
private:
	Boards* myBoard;
public:
	/************************************
	 * Constructor/Deconstructor
	 ***********************************/
 	Players();
	~Players();
	/************************************
	 * Get/Set Functions
	 ***********************************/
	Boards* getBoard() const;
	void setBoard(Boards* newBoard);
	/************************************
	 * Functions
	 ***********************************/
};
#endif
