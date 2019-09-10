#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Executive.h"
#include "Boards.h"

Executive::Executive(){

}
Executive::~Executive(){
}
void Executive::run(){
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
 
 //Checks if the user entered values are on the board
 //Returns true is '~' water is found
 if(newBoard->isValid(column, row)){
   std::cout << "Is valid..\n";
 }
 else{
   std::cout << "Invalid location\n";
 }
}
