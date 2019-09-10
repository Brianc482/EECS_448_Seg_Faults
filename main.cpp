#include <iostream>
#include "Executive.h"

int main(int argc, char* argv[]){
    if(argc < 1){
        std::cout << "Incorrect number of parameters!\n";
    }
    else{
        Executive exec;
        exec.run();
    }
    return(0);
}
