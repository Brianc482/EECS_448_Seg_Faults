#include "Boards.h"
using namespace std;

Boards::Boards(){
  /*Default values put into rows and columns.*/
  rows = 8;
  cols = 8;
  /*Creating the board, implemented as a 2-D array of
    characters on the heap.*/
  myBoard = new char*[rows];
  for(int i = 0 ; i < rows ; i++) {
    myBoard[i] = new char[cols];
  }
  /*Fill the default board with "water".*/
  for(int a = 0 ; a < rows ; a++) {
    for(int b = 0 ; b < cols ; b++) {
      myBoard[a][b] = '~';
    }
  }

}

Boards::~Boards(){
  /*Deletes the allocated memory for the board.*/
  for(int d = 0 ; d < rows ; d++) {
    delete[] myBoard[d];
  }
  delete[] myBoard;
  myBoard = nullptr; //Repoints to null, for safety.
}

void Boards::displayBoard(bool personal) const{
  char temp = '~';
  for(int x = 0 ; x < rows ; x++) {
    for(int y = 0 ; y < cols ; y++) {
      temp = myBoard[x][y];
      if((personal == false) && (temp == 'S')) {
        cout<<'~';
      } else {
        cout<<temp;
      }
    }
  }
}
