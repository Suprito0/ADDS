#include "Pirate.h"

Pirate::Pirate(){
    this->moveName = "Pirate";
    this->canDefeat = {"Monkey", "Robot"};
}
string Pirate::getName() {
    return this->moveName;
}