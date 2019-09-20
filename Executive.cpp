#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>
//#include <stdlib.h>
#include "Executive.h"

Executive::Executive(){
  std::cout << " ____        _   _   _      ____  _     _\n"
    << "| __ )  __ _| |_| |_| | ___/ ___|| |__ (_)_ __\n"
    << "|  _ \\ / _` | __| __| |/ _ \\___ \\| '_ \\| | '_ \\\n"
    << "| |_) | (_| | |_| |_| |  __/___) | | | | | |_) |\n"
    << "|____/ \\__,_|\\__|\\__|_|\\___|____/|_| |_|_| .__/\n"
    << "                                        |_|\n";
  row = numberOfShips = choice = 0;
  column = ' ';
  player1 = new Players();
  player2 = new Players();
  displayMenu();
}
Executive::~Executive(){
    player1->setID(" ");
    player2->setID(" ");
    delete player1;
    delete player2;
}
void Executive::displayMenu(){
    std::cout << "\nPlease make a selection: \n";
    std::cout << "1. Start a 2 player game\n";
    std::cout << "2. Exit\n";
    int choice = 0;
	while (choice != 2) {
		std::cout << "\nEnter your choice: ";
		std::cin >> choice;
		while (std::cin.fail() || choice > 2 || choice < 1){
        std::cin.clear();
        std::cin.ignore(INT8_MAX, '\n');
        std::cout << "Invalid selection, try again.\n";
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        }
        if(choice == 1){
            run();
        }
        else if(choice == 2){
            std::cout << "Goodbye!\n";
            exit(0);
        }
    }
}
void Executive::run(){
 setPlayer1Name();
 setPlayer2Name();
 std::cout << "\n\nGreat! Now lets decide how many ships to play with.\n";
 std::cout << "The number of ships must be at least 1 and no more than 5.\n";
 getNumberOfShips();

 player1->setShips(numberOfShips);
 //system("CLS");
 player2->setShips(numberOfShips);
 //system("CLS");
 if(player1->shipsSet() == true && player2->shipsSet() == true){
    while(player1->hasLost() == false && player2->hasLost() == false){
        player1->getBoards();
        std::cout << "\n" << player1->getID() << " it's your turn!\n";
        getColumn();
        getRow();
        if(player2->getHit(column, row) == true){
            std::cout << "\nHIT!!!\n";
            player2->markMyHits(column, row);
            player1->markTheirHits(column, row);
        }
        else{
            std::cout << "\nMISS!!!\n";
            player2->markMyMisses(column, row);
            player1->markTheirMisses(column, row);
        }
        player2->getBoards();
        std::cout << "\n" << player2->getID() << " it's your turn!\n";
        getColumn();
        getRow();
        if(player1->getHit(column, row) == true){
            std::cout << "\nHIT!!!\n";
            player1->markMyHits(column, row);
            player2->markTheirHits(column, row);

        }
        else{
            std::cout << "\nMISS!!!\n";
            player1->markMyMisses(column, row);
            player2->markTheirMisses(column, row);
        }
    }
    if(player1->hasLost() == true || player2->hasLost() == true){
        if(player2->hasLost() == true){
            player1->markMyHits(column, row);
            std::cout << player1->getID() << " has won the game!!!\n";
            player1->getOffensiveBoard();
            player1->getDefensiveBoard();
            displayMenu();
        }
        else if(player1->hasLost() == true){
            player2->markMyHits(column, row);
            std::cout << player2->getID() << " has won the game!!!\n";
            player2->getOffensiveBoard();
            player2->getDefensiveBoard();
            displayMenu();
        }
    }
 }
}
void Executive::setPlayer1Name(){
    std::string player1Name = " ";
    std::cout << "Enter the name of Player #1: ";
    std::cin >> player1Name;
    std::cout << "Welcome " << player1Name << "!\n";
    player1->setID(player1Name);
}
void Executive::setPlayer2Name(){
    std::string player2Name = " ";
    std::cout << "Enter the name of Player #2: ";
    std::cin >> player2Name;
    std::cout << "Welcome " << player2Name << "!\n";
    player2->setID(player2Name);
}
void Executive::getP1Name(){
    std::cout << player1->getID() << "\n";
}
void Executive::getP2Name(){
    std::cout << player2->getID() << "\n";
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
  column = (toupper(column));
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
