#include "Robot.h"

Robot::Robot(){
    this->moveName = "Robot";
    this->canDefeat = {"Zombie", "Ninja"};
}

string Robot::getName() {
    return this->moveName;
}
