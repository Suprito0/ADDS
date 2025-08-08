#include "Paper.h"

Paper::Paper(){
    this->moveName = "Paper";
    this->canDefeat = {"Rock"};
}

string Paper::getName() {
    return this->moveName;
}
