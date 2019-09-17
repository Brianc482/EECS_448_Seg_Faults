#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Executive.h"

Executive::Executive(){
  row = numberOfShips = 0;
  column = ' ';
  newBoard = new Boards();
}
Executive::~Executive(){


}
void Executive::run(){
 getNumberOfShips();
 getColumn();
 getRow();

 newBoard->displayOffensiveBoard();
 newBoard->displayDefensiveBoard();
 newBoard->displayBoth();

 checkShot();
 newBoard->displayDefensiveBoard();
}
void Executive::getNumberOfShips(){
  std::cout << "Enter the number of ships(1-5): ";
  std::cin >> numberOfShips;
  while (std::cin.fail() || numberOfShips > 5 || numberOfShips < 1){
    std::cin.clear();
    std::cin.ignore(INT8_MAX, '\n');
    std::cout << "Invalid number of ships, try again.\n";
    std::cout << "\nEnter the number of ships: ";
    std::cin >> numberOfShips;
  }
}
void Executive::getColumn(){
  std::cout << "\nEnter the column letter: ";
  std::cin >> column;
  while(column < 65 || column > 72){
    if(column < 65 || column > 72){
    std::cout << "Invalid selection, try again\n";
    std::cout << "Enter the column letter: ";
    std::cin >> column;
   }
   else{
     std::cin >> column;
   }
  }
}
void Executive::getRow(){
  std::cout << "\nEnter the row number: ";
  std::cin >> row;
  while (std::cin.fail() || row > 7 || row < 0){
    std::cin.clear();
    std::cin.ignore(INT8_MAX, '\n');
    std::cout << "Invalid selection, try again.\n";
    std::cout << "\nEnter the row number: ";
    std::cin >> row;
  }
}
void Executive::checkShot(){
  if(newBoard->isValid(column, row)){
    std::cout << "Is valid..\n";
    if(newBoard->isHit(column, row)){
      std::cout << "HIT!!!!\n";
    }
    else{
      std::cout << "MISS!!!!\n";
    }
  }
  else{
    std::cout << "Invalid location\n";
  }
}
