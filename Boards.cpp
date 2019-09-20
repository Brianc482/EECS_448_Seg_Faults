#include "Boards.h"
#include <iostream>
using namespace std;

Boards::Boards(){
  /*Default values put into rows and columns.*/
  rows = 8;
  cols = 8;
  /*Creating the boards,both are implemented as 2-D arrays of
    characters on the heap.*/
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0; j < cols; j++){
      offensiveBoard[i][j] = '~';
      defensiveBoard[i][j] = '~';
    }
  }
}
Boards::~Boards(){
  //Deletes the allocated memory for the boards.
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < rows ; j++) {
      offensiveBoard[i][j] = ' ';
      defensiveBoard[i][j] = ' ';
    }
  }
  free(offensiveBoard);
  free(defensiveBoard);
}
//Checks the position within the board containing ships
//If the location in the array contains a ~ the position
//is considered valid and true is returned, else false.
bool Boards::isValid(int column, int row){
  if((column <= 7 && column >= 0) && (row <= 7 && row >= 0)){
    if(defensiveBoard[column][row] == '~'){
      return true;
    }
  }
  return false;
}
//Displays the offensive board of hits and misses for the
//current player
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
///Displays the offensive board of hits and misses for the
//current player
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
//Displays both the offensive and defensive boards for a player
void Boards::displayBoth() const{
  cout << "\nYour hits and misses: \n";
  displayOffensiveBoard();
  cout << "\nYour ships: \n";
  displayDefensiveBoard();
}
//Checks the designated location in the array for 'S' and returns true
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
//Used while setting the ships in the beginning of the game,
//marks the designated location within the arrays
void Boards::markShips(int column, int row){
    defensiveBoard[row][column] = 'S';
    displayDefensiveBoard();
}
//If no more ships('S') exist within the array returns true
//else returns false
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
//Returns the character located at the specified position
char Boards::getLocation(int column, int row){
    return defensiveBoard[row][column];
}
//Marks the board with either an 'H' if a ship 'S' is found
//or an 'M' if water '~' is found
void Boards::boardShot(int column, int row){
    if(getLocation(column, row) == 'S'){
        offensiveBoard[row][column] = 'H';
    }
    else{
        offensiveBoard[row][column] = 'M';
    }
}
//The following two methods are used to mark the arrays when
//the player is on offense(shooting at the ships).
//This method marks when a hit has occurred
void Boards::ownBoardHit(int column, int row){
    defensiveBoard[row][column] = 'H';
}
//This method marks when a miss has occurred
void Boards::ownBoardMiss(int column, int row){
    defensiveBoard[row][column] = 'M';
}
//The following two methods are used to mark the arrays when
//the player is on defense(being shot at).
//This method marks when a hit has occurred
void Boards::otherBoardHit(int column, int row){
    offensiveBoard[row][column] = 'H';
}
//This method marks when a miss has occurred
void Boards::otherBoardMiss(int column, int row){
    offensiveBoard[row][column] = 'M';
}

void Boards::clearBoards(){
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0; j < cols; j++){
      offensiveBoard[i][j] = '~';
      defensiveBoard[i][j] = '~';
    }
  }
}
