#include "Referee.h"

Referee::Referee(){}

Player* Referee::refGame(Player* player1, Player* player2){
    Move* player1move = player1->makeMove();
    Move* player2move = player2->makeMove();

    if (player1move->getMoveName() == player2move->getMoveName()){
        return nullptr;
    }
    for (string defeat : player1move->getCanDefeat()){
        if (defeat == player2move->getMoveName()){
            return player1;
        }
    }
    return player2;
}