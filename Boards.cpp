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
      myBoard[i][j] = '~';
    }
  }
}
//Converts the letter for column into a number
int Boards::charConvert(char temp){
  int columnNumber = 0;
  if(temp == 'A' || temp == 'a'){
    columnNumber = 0;
  }
  if(temp == 'B' || temp == 'b'){
    columnNumber = 1;
  }
  if(temp == 'C' || temp == 'c'){
    columnNumber = 2;
  }
  if(temp == 'D' || temp == 'd'){
    columnNumber = 3;
  }
  if(temp == 'E' || temp == 'e'){
    columnNumber = 4;
  }
  if(temp == 'F' || temp == 'f'){
    columnNumber = 5;
  }
  if(temp == 'G' || temp == 'g'){
    columnNumber = 6;
  }
  if(temp == 'H' || temp == 'h'){
    columnNumber = 7;
  }
  return columnNumber;
}
bool Boards::isValid(char column, int row){
  int columnNumber = charConvert(column);
  if((columnNumber <= 7 && columnNumber >= 0) && (row <= 7 && row >= 0)){
      return true;
  }
  return false;
}
Boards::~Boards(){
  //Deletes the allocated memory for the board.
  for(int i = 0 ; i < rows ; i++) {
    for(int j = 0 ; j < rows ; j++) {
      myBoard[i][j] = ' ';
    }
  }
  delete myBoard;
}
//Displays the board
void Boards::displayBoard() const{
  cout << "  A B C D E F G H\n";
  for(int i = 0; i < rows; i++) {
    cout << i << " ";
    for(int j = 0; j < 8; j++) {
      cout <<  myBoard[i][j] << " ";
    }
    cout << "\n";
  }
}
//Checks the location in the array for 'S' and returns true
//If that position is '~', 'M', or 'H' returns false
bool Boards::isHit(char column, int row){
 int columnNumber = charConvert(column);
 if((columnNumber <= 7 && columnNumber >= 0) && (row <= 7 && row >= 0)){
  if(myBoard[row][columnNumber] == 'S'){
    myBoard[row][columnNumber] = 'H';
    return true;
  } else if(myBoard[row][columnNumber] == 'H'){
    cout << "You've already guessed there, you forfeit your turn!\n";
  } else {
    myBoard[row][columnNumber] = 'M';
  }
 }
 return false;
}
//Displays the board, but hides the ships, so you can't cheat.
//Same basic code as the other displays.
void Boards::displayHidden() const {
  char temp = '~';
  cout << "  A B C D E F G H\n";
  for(int i = 0; i < rows; i++) {
    cout << i << " ";
    for(int j = 0; j < 8; j++) {
      temp = myBoard[i][j];
      if(temp == 'S') {
        cout << '~' << " ";
      } else {
        cout <<  myBoard[i][j] << " ";
      }
    }
    cout << "\n";
  }
}
