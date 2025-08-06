#include "Human.h"

Human::Human(){
    this->name = "Human";
}
Move* Human::makeMove(){
    string move;
    // cout << this->getName() << ", make your move." << endl;
    // cout << "Enter r to play Rock, p to play paper, s to play scissor" << endl;
    cin >> move;
    static_cast<Move>(move);
    
}