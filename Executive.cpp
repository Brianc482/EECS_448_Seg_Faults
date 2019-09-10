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
 if(newBoard->isValid('P', 4)){
   std::cout << "Is valid..\n";
 }
 else{
   std::cout << "Invalid location\n";
 }
 delete newBoard;
}
