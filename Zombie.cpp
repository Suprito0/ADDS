#include "Zombie.h"

Zombie::Zombie(){
    this->moveName = "Zombie";
    this->canDefeat = {"Monkey", "Pirate"};
}

string Zombie::getName() {
    return this->moveName;
}