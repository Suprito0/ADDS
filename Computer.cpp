#include "Computer.h"

Computer::Computer(){
    this->name = "Computer";
}

Move* Computer::makeMove(){
    return new Rock();
}