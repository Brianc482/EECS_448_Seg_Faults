#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Executive.h"
#include<stdio.h>
Executive::Executive()
{
  row = numberOfShips = 0;
  column = ' ';
  playerOne = new Boards();
  playerTwo = new Boards();
}


Executive::~Executive()
{


}


void Executive::run()
{
  //int choice;
  //int choice2;
  int r1,r2,c1,c2;
  int a;
  char b;
  char co1, co2;
  std::cout<<" ____        _   _   _      ____  _     _\n"<<"| __ )  __ _| |_| |_| | ___/ ___|| |__ (_)_ __\n"<<"|  _ \\ / _` | __| __| |/ _ \\___ \\| '_ \\| | '_ \\\n"<<"| |_) | (_| | |_| |_| |  __/___) | | | | | |_) |\n"<<"|____/ \\__,_|\\__|\\__|_|\\___|____/|_| |_|_| .__/\n"<<"                                        |_|\n";

  playerOne->getNumberOfShips();
  playerOne->displayBoard();

  playerTwo->getNumberOfShips();
  playerTwo->displayBoard();

  cout << "Game Begins now!" << endl;

  while(!(playerOne->isGameOver()) || !(playerTwo->isGameOver()) ) //the game keep going, when isGameover() is false;
  {
    playerOne->displayBoard();
    cout << "Player1 starts hitting Player2." << endl;
    cout << "Where you wanna fire at: ";
    cin >> a >> b;

    playerTwo->checkShot(b,a);

    if(playerTwo->isHit(b,a))
    {
      playerOne->FireHit(b,a);
    }
    else
    {
      playerOne->FireMiss(b,a);
    }


    cout << "Player2 starts hitting Player1." << endl;
    cout << "Where you wanna fire at: ";
    cin >> a >> b;
    playerOne->checkShot(b,a);

    if(playerOne->isHit(b,a))
    {
      playerTwo->FireHit(b,a);
    }
    else
    {
      playerTwo->FireMiss(b,a);
    }
  }
  cout << "Game Ends !" << endl;
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



void Executive::addSpace(int num){
  for(int s = 0 ; s < num ; s++) {
    std::cout<< "\n";
  }
}
