#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Executive.h"
#include<stdio.h>
Executive::Executive(){
  row = numberOfShips = 0;
  column = ' ';
  playerOne = new Boards();
  playerTwo = new Boards();
}
Executive::~Executive(){


}
void Executive::run(){
  //int choice;
  //int choice2;
  int r1,r2,c1,c2;
  char co1, co2;
  std::cout<<" ____        _   _   _      ____  _     _\n"<<"| __ )  __ _| |_| |_| | ___/ ___|| |__ (_)_ __\n"<<"|  _ \\ / _` | __| __| |/ _ \\___ \\| '_ \\| | '_ \\\n"<<"| |_) | (_| | |_| |_| |  __/___) | | | | | |_) |\n"<<"|____/ \\__,_|\\__|\\__|_|\\___|____/|_| |_|_| .__/\n"<<"                                        |_|\n";
/*std::cout<<"1)Start Game\n";
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
        playerOne->displayOffensiveBoard();
        std::cout<<"1)Display Offensive Board\n";
        std::cout<<"2)Display Defensive Board\n";
        std::cout<<"3)Display Both Players\n";
        std::cin>>choice2;
      }
      while (choice2==2){
        playerOne->displayDefensiveBoard();
        std::cout<<"1)Display Offensive Board\n";
        std::cout<<"2)Display Defensive Board\n";
        std::cout<<"3)Display Both Players\n";
        std::cin>>choice2;
      }
      while (choice2==3){
        playerOne->displayBoth();
        std::cout<<"1)Display Offensive Board\n";
        std::cout<<"2)Display Defensive Board\n";
        std::cout<<"3)Display Both Players\n";
        std::cin>>choice2;
      }

    }

 addSpace(60);
 checkShot();
*/
 /*playerOne->displayBoard();
 getNumberOfShips();
 for(int i = 1 ; i <= numberOfShips ; i++) {
   std::cout<<"Please place your ship of size "<< i << '\n';
   std::cout<<"What space does the ship start in?\n";
   if()
   shipCheck()
 }
*/
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
  if(playerOne->isValid(column, row)){
    std::cout << "Is valid..\n";
    if(playerOne->isHit(column, row)){
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

void Executive::addSpace(int num){
  for(int s = 0 ; s < num ; s++) {
    std::cout<< "\n";
  }
}
