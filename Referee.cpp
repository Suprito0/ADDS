#include "Referee.h"

Referee::Referee(){}

Player* Referee::refGame(Player* player1, Player* player2){
    Move* player1move = player1->makeMove();
    Move* player2move = player2->makeMove();

    if (player1move->getName() == player2move->getName()){
        return nullptr;
    }
    for (string defeat : player1move->getCanDefeat()){
        if (defeat == player2move->getName()){
            return player1;
        }
    }
    return player2;
}