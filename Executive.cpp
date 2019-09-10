#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Executive.h"

Executive::Executive(){
 row = 0;
 column = ' ';
 newBoard = new Boards();
}
Executive::~Executive(){
}
void Executive::run(){
 //Prompts the user for the number of ships to be used during the game
 int numberOfShips = 0;
 std::cout << "Enter the number of ships(1-5): ";
 std::cin >> numberOfShips;
 //If the value entered is invalid, prompts the user for a new value 
 //until a valid value is entered
 while (std::cin.fail() || numberOfShips > 5 || numberOfShips < 1){
   std::cin.clear();
   std::cin.ignore(INT8_MAX, '\n');
   std::cout << "Invalid number of ships, try again.\n";
   std::cout << "\nEnter the number of ships: ";
   std::cin >> numberOfShips;
 }
 
 Boards* newBoard = new Boards();
 newBoard->displayOffensiveBoard();
 newBoard->displayOffensiveBoard();
 newBoard->displayBoth();
 
 //Sets the row and column if the input is valid
 int row = 0;
 char column = ' ';
 std::cout << "\nEnter the column letter: ";
 std::cin >> column;
 
 //If the column value is not between A-H prompt for new input
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
 
 std::cout << "\nEnter the row number: ";
 std::cin >> row;

 //If the row value is not between A-H prompt for new input
 while (std::cin.fail() || row > 7 || row < 0){
   std::cin.clear();
   std::cin.ignore(INT8_MAX, '\n');
   std::cout << "Invalid selection, try again.\n";
   std::cout << "\nEnter the row number: ";
   std::cin >> row;
 }
 checkShot();
}
 //Checks if the user entered values are on the board
 //Returns true is '~' water is found
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

