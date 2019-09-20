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
bool Boards::isValid(int column, int row){
  if((column <= 7 && column >= 0) && (row <= 7 && row >= 0)){
    if(defensiveBoard[column][row] == '~'){
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
  free(offensiveBoard);
  free(defensiveBoard);
}
//Displays both the offensive and defensive boards for a player
void Boards::displayBoth() const{
  cout << "\nYour hits and misses: \n";
  displayOffensiveBoard();
  cout << "\nYour ships: \n";
  displayDefensiveBoard();
}
//Displays the current offensive board
void Boards::displayOffensiveBoard() const{
  cout << "\n  A B C D E F G H\n";
  for(int i = 0; i < rows; i++) {
    cout << i << " ";
    for(int j = 0; j < 8; j++) {
      cout <<  offensiveBoard[i][j] << " ";
    }
    cout << "\n";
  }
}
//Displays the current defensive board
void Boards::displayDefensiveBoard() const{
  cout << "\n  A B C D E F G H\n";
  for(int i = 0; i < rows; i++) {
    cout << i << " ";
    for(int j = 0; j < 8; j++) {
      cout <<  defensiveBoard[i][j] << " ";
    }
    cout << "\n";
  }
}
//Checks the location in the array for 'S' and returns true
//If that position is '~', 'M', or 'H' returns false
bool Boards::isHit(int column, int row){
 bool shipHit = false;
 if((column <= 7 && column >= 0) && (row <= 7 && row >= 0)){
  if(defensiveBoard[row][column] == 'S'){
    defensiveBoard[row][column] = 'H';
    shipHit = true;
  }
  else{
    defensiveBoard[row][column] = 'M';
  }
  return shipHit;
 }
 return shipHit;
}
void Boards::markShips(int column, int row){
    defensiveBoard[row][column] = 'S';
    displayDefensiveBoard();
}
bool Boards::gameWon(){
    bool gameOver = true;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(defensiveBoard[i][j] == 'S'){
                gameOver = false;
                return gameOver;
            }
        }
    }
    return gameOver;
}
char Boards::getLocation(int column, int row){
    return defensiveBoard[row][column];
}
void Boards::boardShot(int column, int row){
    if(getLocation(column, row) == 'S'){
        offensiveBoard[row][column] = 'H';
    }
    else{
        offensiveBoard[row][column] = 'M';
    }
}
void Boards::ownBoardHit(int column, int row){
    defensiveBoard[row][column] = 'H';
}
void Boards::ownBoardMiss(int column, int row){
    defensiveBoard[row][column] = 'M';
}
void Boards::otherBoardHit(int column, int row){
    offensiveBoard[row][column] = 'H';
}
void Boards::otherBoardMiss(int column, int row){
    offensiveBoard[row][column] = 'M';
}
