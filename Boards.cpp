#include "Boards.h"
#include <iostream>
using namespace std;

Boards::Boards(){
  /*Default values put into rows and columns.*/
  rows = 8;
  cols = 8;
  /*Creating the board, implemented as a 2-D array of
    characters on the heap.*/
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0; j < cols; j++){
      offensiveBoard[i][j] = '~';
      defensiveBoard[i][j] = '~';
    }
  }
}
bool Boards::isValid(char column, int row){
  int columnNumber;
  if(column == 'A'){
    columnNumber = 0;
  }
  if(column == 'B'){
    columnNumber = 1;
  }
  if(column == 'C'){
    columnNumber = 2;
  }
  if(column == 'D'){
    columnNumber = 3;
  }
  if(column == 'E'){
    columnNumber = 4;
  }
  if(column == 'F'){
    columnNumber = 5;
  }
  if(column == 'G'){
    columnNumber = 6;
  }
  if(column == 'H'){
    columnNumber = 7;
  }
  if((columnNumber <= 7 && columnNumber >= 0) && (row <= 7 && row >= 0)){
    if(defensiveBoard[columnNumber][row] == '~'){
      return true;
    }
  }
  return false;
}
Boards::~Boards(){
  //Deletes the allocated memory for the board.
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < rows ; j++) {
      offensiveBoard[i][j] = ' ';
      defensiveBoard[i][j] = ' ';
    }
  }
  delete offensiveBoard;
  delete defensiveBoard;
}
void Boards::displayBoth() const{
  cout << "\nOffensive board: \n";
  displayOffensiveBoard();
  cout << "\nDefensive board: \n";
  displayDefensiveBoard();
}

void Boards::displayOffensiveBoard() const{
  cout << "  A B C D E F G H\n";
  for(int i = 0; i < rows; i++) {
    cout << i << " ";
    for(int j = 0; j < 8; j++) {
      cout <<  offensiveBoard[i][j] << " ";
    }
    cout << "\n";
  }
}
void Boards::displayDefensiveBoard() const{
  cout << "  A B C D E F G H\n";
  for(int i = 0; i < rows; i++) {
    cout << i << " ";
    for(int j = 0; j < 8; j++) {
      cout <<  defensiveBoard[i][j] << " ";
    }
    cout << "\n";
  }
}

bool Boards::isHit(char column, int row){
	/* TODO 
		Create isHit */
	return false;
}
