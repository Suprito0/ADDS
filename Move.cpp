#include"Move.h"

vector<string> Move::getCanDefeat(){
    return this->canDefeat;
}

Player* Move::play(Player* player1, Player* player2) {
    Move* player1move = player1->makeMove();
    Move* player2move = player2->makeMove();
    for (string defeat : player1move->getCanDefeat()){
        if (defeat == player2move->getName()){
            return player1;
        }
    }

    for (string defeat : player2move->getCanDefeat()){
    if (defeat == player1move->getName()){
        return player2;
    }
    }

    return nullptr; 
}