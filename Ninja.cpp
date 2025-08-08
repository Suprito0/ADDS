#include "Ninja.h"

Ninja::Ninja(){
    this->moveName = "Ninja";
    this->canDefeat = {"Pirate", "Zombie"};
}

string Ninja::getName() {
    return this->moveName;
}