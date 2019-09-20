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
int Boards::charConvert(char temp)
{
  int columnNumber = 0;
  if(temp == 'A' || temp == 'a')
  {
    columnNumber = 0;
  }
  if(temp == 'B' || temp == 'b')
  {
    columnNumber = 1;
  }
  if(temp == 'C' || temp == 'c')
  {
    columnNumber = 2;
  }
  if(temp == 'D' || temp == 'd')
  {
    columnNumber = 3;
  }
  if(temp == 'E' || temp == 'e')
  {
    columnNumber = 4;
  }
  if(temp == 'F' || temp == 'f')
  {
    columnNumber = 5;
  }
  if(temp == 'G' || temp == 'g')
  {
    columnNumber = 6;
  }
  if(temp == 'H' || temp == 'h')
  {
    columnNumber = 7;
  }
  return columnNumber;
}

char Boards::intConvert(int temp)
{
  char column = 'A';
  if(temp == 0)
  {
    column = 'A';
  }
  if(temp == 1)
  {
    column = 'B';
  }
  if(temp == 2)
   {
    column = 'C';
  }
  if(temp == 3)
  {
    column = 'D';
  }
  if(temp == 4)
  {
    column = 'E';
  }
  if(temp == 5)
  {
    column = 'F';
  }
  if(temp == 6)
  {
    column = 'G';
  }
  if(temp == 7)
  {
    column = 'H';
  }
  return column;
}

bool Boards::isValid(char column, int row)
{
  int columnNumber = charConvert(column);
  if((columnNumber <= 7 && columnNumber >= 0) && (row <= 7 && row >= 0)){
      return true;
  }
  return false;
}

Boards::~Boards()
{
  //Deletes the allocated memory for the board.
  for(int i = 0 ; i < rows ; i++)
  {
    for(int j = 0 ; j < rows ; j++)
    {
      myBoard[i][j] = ' ';
    }
  }
  delete myBoard;
}

//Displays the board
void Boards::displayBoard() const
{
  cout << "  A B C D E F G H\n";
  for(int i = 0; i < rows; i++)
  {
    cout << i << " ";
    for(int j = 0; j < 8; j++)
    {
      cout <<  myBoard[i][j] << " ";
    }
    cout << "\n";
  }
}
//Checks the location in the array for 'S' and returns true
//If that position is '~', 'M', or 'H' returns false
bool Boards::isHit(char column, int row)
{
 int columnNumber = charConvert(column);
 if((columnNumber <= 7 && columnNumber >= 0) && (row <= 7 && row >= 0))
 {
  if(myBoard[row][columnNumber] == 'S')
  {
    //myBoard[row][columnNumber] = 'H';
    return true;
  }
  else if(myBoard[row][columnNumber] == 'H' || myBoard[row][columnNumber] == 'M' )
  {
    cout << "You've already guessed there, you forfeit your turn!\n";
  }
  else
  {
    //myBoard[row][columnNumber] = 'M';
  }
 }
 return false;
}


void Boards::FireHit(char column, int row)
{
  int columnNumber = charConvert(column);

  myBoard[row][columnNumber] = 'H';

}





void Boards::FireMiss(char column, int row)
{
  int columnNumber = charConvert(column);

  myBoard[row][columnNumber] = 'M';

}




//Displays the board, but hides the ships, so you can't cheat.
//Same basic code as the other displays.
void Boards::displayHidden() const
{
  char temp = '~';
  cout << "  A B C D E F G H\n";
  for(int i = 0; i < rows; i++)
   {
    cout << i << " ";
    for(int j = 0; j < 8; j++)
    {
      temp = myBoard[i][j];
      if(temp == 'S') {
        cout << '~' << " ";
      }
      else
      {
        cout <<  myBoard[i][j] << " ";
      }
    }
    cout << "\n";
  }
}

bool Boards::isPlaceable(char col, int row)
{
  char temp;
  int column = charConvert(col);

  if(isValid(col, row))
  {
    temp = myBoard[row][column];
    if(temp == '~')
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    return false;
  }
}

bool Boards::isPlaceableRange(char col1, char col2, int row1, int row2)
{
  int column1 = charConvert(col1);
  int column2 = charConvert(col2);
  //same column, thus vertical
  if(column1 == column2) {
    for(int i = min(row1,row2) ; i <= max(row1,row2) ; i++){
      if(!isPlaceable(col1,i)){
        return false;
      }
    }
    return true;
  //same row, thus horizontal
  } else if(row1 == row2)
  {
    for(int i = min(column1,column2) ; i <= max(column1,column2) ; i++){
      if(!isPlaceable(intConvert(i),row1))
      {
        return false;
      }
    }
    return true;
  //if it's not horizontal or vertical, it can't be placed.
  } else {
    return false;
  }
}

void Boards::shipCheck(int row1, int row2, char col1, char col2, int size) {
  int col1Num = charConvert(col1);
  int col2Num = charConvert(col2);
  //Checks the size of the ship, and places accordingly.
  //1 ship
  if(size == 1 && isValid(col1, row1)) {
    myBoard[row1][col1Num] = 'S';
  } else {
    //Both end points are valid
    if(isValid(col1, row1) && isValid(col2, row2)){
      //if the range of values is placeable upon
      //checks for diagonals here
      if(isPlaceableRange(col1, col2, row1, row2)){
        //Vertical Placement, if the size lines up.
        if(col1Num == col2Num && (abs(row2 - row1)+1 == size)) {
          for(int a = min(row2,row1) ; a <= max(row2,row1) ; a++) {
            placeShip(col1,a);
          }
        //Horizontal Placement, if the sizes line up.
        } else if(row1 == row2 && (abs(col2Num - col1Num)+1 == size)) {
          for(int a = min(col1,col2) ; a <= max(col1,col2) ; a++) {
            placeShip(intConvert(a),row1);
          }
        } else {
          cout<<"Size does not match given values.\n";
        }
      } else {
        cout<<"Ship not in a placeable range.\n";
      }
    } else {
      cout<<"One or both locations invalid.\n";
    }
  }
}

void Boards::placeShip(int row, char col)
{
  int column = charConvert(col);
  myBoard[row][column] = 'S';
}



bool Boards::isGameOver()
{
  for(int i = 0; i < rows; i++)
  {
    for(int k = 0; k < cols; k++)
    {
      if(myBoard[i][k] == 'S')
      {
        return false;
      }
    }
  }
  return true;
}

void Boards::replace(char col,int row){
  int column = charConvert(col);
  myBoard[row][column] = 'X';
}

void Boards::checkShot(char X,int Y)
{
  if(isValid(X, Y))
  {
    std::cout << "Is valid..\n";
    if(isHit(X, Y))
    {
      std::cout << "HIT!!!!\n";
    }
    else
    {
      std::cout << "MISS!!!!\n";
    }
  }
  else
  {
    std::cout << "Invalid location\n";
  }
}

void Boards::getNumberOfShips()
{
  std::cout << "Enter the number of ships(1-5): ";
  std::cin >> numberOfShips;
  while (std::cin.fail() || numberOfShips > 5 || numberOfShips < 1)
  {
    std::cin.clear();
    std::cin.ignore(INT8_MAX, '\n');
    std::cout << "Invalid number of ships, try again.\n";
    std::cout << "\nEnter the number of ships: ";
    std::cin >> numberOfShips;
  }


  //for(int i = 1; i <= numberOfShips; i++)

    int a,c,e,g,i;
    char b,d,f,h,j;

    if(numberOfShips == 1)
    {
      cout << "Where you want to put this ship at:(Row Number First then Col Letter) ";
      cin >> a >> b; //first ship's location 1x1
      placeShip(a,b);
    }
    else if(numberOfShips == 2)
    {
      cout << "Where you want to put the first ship(1x1) at:(Row Number First then Col Letter) ";
      cin >> a >> b; //first ship's location 1x1
      placeShip(a,b);
      cout <<"How about the second ship's location now(size:1x2):(Row Number First then Col Letter) ";
      cin >> c >> d;
      cin >> e >> f;
      placeShip(c,d);
      placeShip(e,f);
    }
    else if(numberOfShips == 3)
    {
      cout << "Where you want to put the first ship(1x1) at:(Row Number First then Col Letter) ";
      cin >> a >> b; //first ship's location 1x1
      placeShip(a,b);
      cout << "How about the second ship's location now(size:1x2):(Row Number First then Col Letter) ";
      cin >> c >> d;
      cin >> e >> f;
      placeShip(c,d);
      placeShip(e,f);
      cout << "How about the third ship's location now(size:1x3):(Row Number First then Col Letter) ";
      cin >> a >> b;
      cin >> c >> d;
      cin >> e >> f;
      placeShip(a,b);
      placeShip(c,d);
      placeShip(e,f);
    }
    else if(numberOfShips == 4)
    {
      cout << "Where you want to put the first ship(1x1) at:(Row Number First then Col Letter) ";
      cin >> a >> b; //first ship's location 1x1
      placeShip(a,b);
      cout << "How about the second ship's location now(size:1x2):(Row Number First then Col Letter) ";
      cin >> c >> d;
      cin >> e >> f;
      placeShip(c,d);
      placeShip(e,f);
      cout << "How about the third ship's location now(size:1x3):(Row Number First then Col Letter) ";
      cin >> a >> b;
      cin >> c >> d;
      cin >> e >> f;
      placeShip(a,b);
      placeShip(c,d);
      placeShip(e,f);
      cout << "How about the 4th ship's location now(size:1x4):(Row Number First then Col Letter) ";
      cin >> a >> b;
      cin >> c >> d;
      cin >> e >> f;
      cin >> g >> h;
      placeShip(a,b);
      placeShip(c,d);
      placeShip(e,f);
      placeShip(g,h);
    }
    else if(numberOfShips == 5)
    {
      cout << "Where you want to put the first ship(1x1) at:(Row Number First then Col Letter) ";
      cin >> a >> b; //first ship's location 1x1
      placeShip(a,b);
      cout << "How about the second ship's location now(size:1x2):(Row Number First then Col Letter) ";
      cin >> c >> d;
      cin >> e >> f;
      placeShip(c,d);
      placeShip(e,f);
      cout << "How about the third ship's location now(size:1x3):(Row Number First then Col Letter) ";
      cin >> a >> b;
      cin >> c >> d;
      cin >> e >> f;
      placeShip(a,b);
      placeShip(c,d);
      placeShip(e,f);
      cout << "How about the 4th ship's location now(size:1x4):(Row Number First then Col Letter) ";
      cin >> a >> b;
      cin >> c >> d;
      cin >> e >> f;
      cin >> g >> h;
      placeShip(a,b);
      placeShip(c,d);
      placeShip(e,f);
      placeShip(g,h);
      cout << "How about the 5th ship's location now(size:1x5):(Row Number First then Col Letter) ";
      cin >> a >> b;
      cin >> c >> d;
      cin >> e >> f;
      cin >> g >> h;
      cin >> i >> j;
      placeShip(a,b);
      placeShip(c,d);
      placeShip(e,f);
      placeShip(g,h);
      placeShip(i,j);
    }
}
