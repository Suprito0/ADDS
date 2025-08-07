#include "Computer.h"
#include "Rock.h"
#include "Paper.h"
#include "Scissors.h"
#include "Robot.h"
#include "Monkey.h"
#include "Pirate.h"
#include "Ninja.h"
#include "Zombie.h"

Computer::Computer(){
    this->name = "Computer";
}

Move* Computer::makeMove(){
    return new Rock();
}