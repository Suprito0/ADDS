#include "Scissors.h"

Scissors::Scissors(){
    this->moveName = "Scissors";
    this->canDefeat = {"Paper"};
}

string Scissors::getName() {
    return this->moveName;
}