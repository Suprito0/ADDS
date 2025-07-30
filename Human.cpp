#include "Human.h"

Human::Human(){
    this->name = "Human";
}
char Human::makeMove(){
    char move;
    // cout << this->getName() << ", make your move." << endl;
    // cout << "Enter r to play Rock, p to play paper, s to play scissor" << endl;
    cin >> move;
    return move;
}