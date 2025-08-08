#include "Monkey.h"

Monkey::Monkey(){
    this->moveName = "Monkey";
    this->canDefeat = {"Ninja", "Robot"};
}

string Monkey::getName() {
    return this->moveName;
}