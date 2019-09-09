program: main.o Executive.o Players.o Boards.o
	g++ -std=c++11 -g -Wall main.o Executive.o Players.o Boards.o -o program

main.o: main.cpp Executive.cpp 
	g++ -std=c++11 -g -Wall -c  main.cpp 

Executive.o: Executive.h Executive.cpp 
	g++ -std=c++11 -g -Wall -c  Executive.cpp 

Players.o: Players.h 
	g++ -std=c++11 -g -Wall -c  Players.cpp 

Boards.o: Boards.h  
	g++ -std=c++11 -g -Wall -c  Boards.cpp


clean: 
	rm *.o program
