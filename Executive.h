#ifndef EXECUTIVE_H
#define EXECUTIVE_H
#include "Boards.h"
class Executive{
    private:
        int row;
        char column;
        Boards* newBoard;
    public:
        /**
        *@pre none
        *@post primary constructor of the Executive class
        *@post returns nothing
        **/
        Executive();
        /**
        *@pre none
        *@post destructor of the Executive class
        *@post returns nothing
        **/
        ~Executive();
        /**
        *@pre takes a string for the filename
        *@post run determines which mode to run the program in
        *@post returns nothing
        **/
        void run();
        void checkShot();
};
#endif
