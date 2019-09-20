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
  //int r1,r2,c1,c2;
  //bool check;

  int a;
  char b;
  int choice;
  //char co1, co2;
  std::cout<<" ____        _   _   _      ____  _     _\n"<<"| __ )  __ _| |_| |_| | ___/ ___|| |__ (_)_ __\n"<<"|  _ \\ / _` | __| __| |/ _ \\___ \\| '_ \\| | '_ \\\n"<<"| |_) | (_| | |_| |_| |  __/___) | | | | | |_) |\n"<<"|____/ \\__,_|\\__|\\__|_|\\___|____/|_| |_|_| .__/\n"<<"                                        |_|\n";
  std::cout<<"1)Start Game\n";
  std::cout<<"2)Exit\n";
  std::cin>>choice;
  while(choice==1){
  playerOne->getNumberOfShips();
  playerOne->displayBoard();

  playerTwo->getNumberOfShips();
  playerTwo->displayBoard();

  cout << "Game Begins now!" << endl;
  cout << string(50,'\n');

  while(!(playerOne->isGameOver()) || !(playerTwo->isGameOver()) ) //the game keep going, when isGameover() is false;
  {
    cout <<  "Following is playerOne's Board:\n";
    playerOne->displayBoard();
    cout << "Player1 starts hitting Player2." << endl;
    cout << "Where do you wanna fire at: ";
    cin >> a >> b;
cout << string(50,'\n');
    playerTwo->checkShot(b,a);

    if(playerTwo->isHit(b,a))
    {
      playerOne->FireHit(b,a);
      playerTwo->replace(b,a);
    }
    else
    {
      playerOne->FireMiss(b,a);
    }
    if(playerTwo->isGameOver()){
      break;
    }


  
    cout << "Following is playerTwo's Board:\n";
    playerTwo->displayBoard();
    cout << "Player2 starts hitting Player1." << endl;
    cout << "Where do you wanna fire at: ";
    cin >> a >> b;
    cout << string(50,'\n');
    playerOne->checkShot(b,a);

    if(playerOne->isHit(b,a))
    {
      playerTwo->FireHit(b,a);
      playerOne->replace(b,a);
    }
    else
    {
      playerTwo->FireMiss(b,a);
    }
    if(playerOne->isGameOver()){
      break;
    }

  }
  cout << "Game Ends !" << endl;
  cout<<" Would You Like to Start over? \n";
  std::cout<<"1)Hell YEAH\n";
  std::cout<<"2)NO\n";
  std::cin>>choice;
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



void Executive::addSpace(int num){
  for(int s = 0 ; s < num ; s++) {
    std::cout<< "\n";
  }
}
