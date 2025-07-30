#include "Human.h"

Human::Human(){
    this->name = "Player";
}
char Human::makeMove(){
    while(true){
        char move;
        cout << this->getName() << ", make your move." << endl;
        cout << "Enter r to play Rock, p to play paper, s to play scissor" << endl;
        cin >> move;
        if (move == 'r' || move == 'p' || move == 's'){
            return move;
        } else {
            cout << "Invalid input. Try again" << endl;
        }
    }
}