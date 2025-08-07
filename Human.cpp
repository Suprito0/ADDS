#include "Human.h"
#include "Move.h"

Human::Human(){
    this->name = "Human";
}

Human::Human(string name){
    this->name = name;
}

Move* Human::makeMove(){
    string move;
    // cout << this->getName() << ", make your move." << endl;
    // cout << "Enter r to play Rock, p to play paper, s to play scissor" << endl;
    cin >> move;
    if(move =="Rock"){
        return new Rock();
    }
    else if(move == "Paper"){
        return new Paper();
    }
    else if(move == "Scissors"){
        return new Scissors();
    }
    else if(move == "Robot"){
        return new Robot();
    }
    else if(move == "Monkey"){
        return new Monkey();
    }
    else if(move == "Pirate"){
        return new Pirate();
    }
    else if(move == "Ninja"){
        return new Ninja();
    }
    else if(move == "Zombie"){
        return new Zombie();
    }
    return nullptr;
}