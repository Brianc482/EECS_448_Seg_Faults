Battleship: main.o Executive.o Players.o Boards.o
	g++ -std=c++11 -g -Wall main.o Executive.o Players.o Boards.o -o Battleship

main.o: main.cpp Executive.h
	g++ -std=c++11 -g -Wall -c  main.cpp

Executive.o: Executive.h Executive.cpp Players.h
	g++ -std=c++11 -g -Wall -c  Executive.cpp

Players.o: Players.h Players.cpp Boards.h
	g++ -std=c++11 -g -Wall -c  Players.cpp

Boards.o: Boards.h Boards.cpp
	g++ -std=c++11 -g -Wall -c  Boards.cpp

clean:
	rm *.o Battleship
