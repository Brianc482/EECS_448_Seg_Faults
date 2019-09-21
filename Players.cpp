#include "Players.h"

Players::Players(){
    ID = " ";
	myBoard = new Boards();
	allSet = false;
	row = 0;
	column = ' ';
}
Players::~Players(){
	delete myBoard;
	ID = " ";
}
void Players::setID(std::string name){
    this->ID = name;
}
std::string Players::getID(){
    return this->ID;
}
void Players::setShips(int number){
  char orientation = ' ';
  std::cout << "\n" << this->ID << " it's your turn to start setting your ships!\n\n";
  std::cout << "The ships can only be placed vertically or horizontally\n";
  std::cout << "Placing a ship diagonally is not allowed.\n";
  int tempRow;
  char tempColumn = ' ';
  for(int i = 0; i < number; i++){
    if(i == 0){
      std::cout << "\n\nThis ship is a 1 X " << i+1 << " ship.\n";
      myBoard->displayDefensiveBoard();
      getColumn();
      getRow();
      myBoard->markShips(charConvert(column), row);
    }
    else{
      std::cout << "\nThis ship is a 1 X " << i+1 << " ship.\n";
      std::cout << "Enter 'V' to place the ship vertically, and 'H' to place the ship horizontally: ";
      std::cin >> orientation;
      orientation = toupper(orientation);
      while(orientation != 'V' && orientation != 'H'){
          std::cout << "Invalid input.\n";
          std::cout << "Enter 'V' for vertically or 'H' for horizontally: ";
          std::cin >> orientation;
          orientation = toupper(orientation);
          std::cout << orientation << "\n";
      }
      for(int j = 0; j < i+1; j++){
          if(j == 0){
            std::cout << "This is the first section to be placed.\n";
          }
          else if(j == 1){
            std::cout << "This is the second section to be placed.\n";
          }
          else if(j == 2){
            std::cout << "This is the third section to be placed.\n";
          }
          else if(j == 3){
            std::cout << "This is the fourth section to be placed.\n";
          }
          else if(j == 4){
            std::cout << "This is the fifth section to be placed.\n";
          }
          row = 0;
          column = ' ';
          myBoard->displayDefensiveBoard();
          std::cout << "\n" << this->ID << " it's your turn!\n\n";
          getColumn();
          getRow();
          if(orientation == 'V'){
              if(myBoard->getLocation(charConvert(column), row) != '~'){
                while(myBoard->getLocation(charConvert(column), row) != '~'){
                  std::cout << "That section of the board is already occupied!\n";
                  getColumn();
                  getRow();
                }
              }
              if((tempRow != row+1 || tempRow != row-1) && (i > 1)){
                while(tempRow != row+1 || tempRow != row-1){
                  std::cout << "The new placement must be adjacent to the previous placement in a vertical line.\n";
                  getRow();
                }
              }
              else if((tempColumn != column) && (j > 0)){
                while(tempColumn != column){
                  std::cout << "The placement must be in the same column as the previous placement.\n";
                  getColumn();
                }
              }
              else{
                  myBoard->markShips(charConvert(column), row);
                  std::cout << "Ship section set!\n";
              }
          }
          else if(orientation == 'H'){
            std::cout << int(tempColumn) << " " << int(column) << "\n";
            if(myBoard->getLocation(charConvert(column), row) != '~'){
              while(myBoard->getLocation(charConvert(column), row) != '~'){
                std::cout << "That section of the board is already occupied!\n";
                getColumn();
                getRow();
              }
            }
            else if((int(tempColumn) != int(tempColumn+1) || int(tempColumn) != int(column-1)) && (j > 1)){
              while(int(tempColumn) != int(tempColumn+1) || int(tempColumn) != int(column-1)){
                std::cout << int(tempColumn) << " " << int(column-1) << " " << int(column+1) <<"\n";
                std::cout << "The new placement must be adjacent to the previous placement in a horizontal line.\n";
                getColumn();
              }
            }
            else if((tempRow != row) && (j > 0)){
              while(tempRow != row){
                std::cout << "The placement must be in the same row as the previous placement.\n";
                getRow();
              }
            }
            else{
                myBoard->markShips(charConvert(column), row);
                std::cout << "Ship section set!\n";
            }
        }
        tempRow = row;
        tempColumn = (toupper(column));
      }
    }
  }
  //set the column and row on the defensive map
  allSet = true;
}
void Players::getBoards() const {
	myBoard->displayBoth();
}
void Players::getOffensiveBoard() const {
	myBoard->displayOffensiveBoard();
}
void Players::getDefensiveBoard() const {
	myBoard->displayDefensiveBoard();
}
void Players::getColumn(){
    std::cout << "Enter the column letter to set the ship: ";
    std::cin >> column;
    column = (toupper(column));
    while(column < 65 || column > 72){
        if(column < 65 || column > 72){
            std::cout << "Invalid selection, try again\n";
            std::cout << "Enter a valid column letter: ";
            std::cin >> column;
            column = (toupper(column));
        }
    }
}
void Players::getRow(){
    std::cout << "Enter the row number to set the ship: ";
    std::cin >> row;
    while (std::cin.fail() || row > 7 || row < 0){
        std::cin.clear();
        std::cin.ignore(INT8_MAX, '\n');
        std::cout << "Invalid selection, try again.\n";
        std::cout << "Enter a valid row number: ";
        std::cin >> row;
    }
}
void Players::markMyHits(char column, int row){
    myBoard->ownBoardHit(charConvert(column), row);
}
void Players::markMyMisses(char column, int row){
    myBoard->ownBoardMiss(charConvert(column), row);
}
void Players::markTheirHits(char column, int row){
    myBoard->otherBoardHit(charConvert(column), row);
}
void Players::markTheirMisses(char column, int row){
    myBoard->otherBoardMiss(charConvert(column), row);
}
bool Players::shipsSet(){
    return this->allSet;
}
bool Players::hasLost(){
    if(myBoard->gameWon() == true){
        return true;
    }
    else{
        return false;
    }
}
bool Players::getHit(char column, int row){
    if(myBoard->getLocation(charConvert(column), row) == 'S'){
        return true;
    }
    else{
        return false;
    }
}
//Converts the letter for column into a number
int Players::charConvert(char temp){
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

void Players::cleanBoard(){
  myBoard->clearBoards();
}
