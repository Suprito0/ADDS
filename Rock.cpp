#include "Rock.h"

Rock::Rock(){
    this->moveName = "Rock";
    this->canDefeat = {"Scissors"};
}

string Rock::getName() {
    return this->moveName;
}
