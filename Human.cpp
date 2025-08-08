#include "Human.h"
#include "factory.cpp"

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
    return Static::factory(move);
}