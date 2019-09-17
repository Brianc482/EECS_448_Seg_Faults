#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Executive.h"
#include<stdio.h>
Executive::Executive(){
  row = numberOfShips = 0;
  column = ' ';
  newBoard = new Boards();
}
Executive::~Executive(){


}
void Executive::run(){
  int choice;
  int choice2;
  std::cout<<" ____        _   _   _      ____  _     _\n"<<"| __ )  __ _| |_| |_| | ___/ ___|| |__ (_)_ __\n"<<"|  _ \\ / _` | __| __| |/ _ \\___ \\| '_ \\| | '_ \\\n"<<"| |_) | (_| | |_| |_| |  __/___) | | | | | |_) |\n"<<"|____/ \\__,_|\\__|\\__|_|\\___|____/|_| |_|_| .__/\n"<<"                                        |_|\n";
  std::cout<<"1)Start Game\n";
  std::cout<<"2)Exit\n";
  std::cout<<"Make Choice:\n";
  std::cin>>choice;
std::cout<<'\a';
  while(choice==1){
 getNumberOfShips();
 getColumn();
 getRow();
std::cout<<"1)Display Offensive Board\n";
std::cout<<"2)Display Defensive Board\n";
std::cout<<"3)Display Both Players\n";
std::cin>>choice2;
while(choice2==1){
  newBoard->displayOffensiveBoard();
  std::cout<<"1)Display Offensive Board\n";
  std::cout<<"2)Display Defensive Board\n";
  std::cout<<"3)Display Both Players\n";
  std::cin>>choice2;
}
while (choice2==2){
  newBoard->displayDefensiveBoard();
  std::cout<<"1)Display Offensive Board\n";
  std::cout<<"2)Display Defensive Board\n";
  std::cout<<"3)Display Both Players\n";
  std::cin>>choice2;
}
 //newBoard->displayOffensiveBoard();
while (choice2==3){
   newBoard->displayBoth();
   std::cout<<"1)Display Offensive Board\n";
   std::cout<<"2)Display Defensive Board\n";
   std::cout<<"3)Display Both Players\n";
   std::cin>>choice2;
}
 //newBoard->displayOffensiveBoard();
 //newBoard->displayBoth();
}

 checkShot();
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

