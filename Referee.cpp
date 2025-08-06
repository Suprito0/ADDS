#include "Referee.h"

Referee::Referee(){}

Player* Referee::refGame(Player* player1, Player* player2){
    char player1move = player1->makeMove();
    char player2move = player2->makeMove();

    if (player1move == player2move){
        return nullptr;
    } else if ((player1move == 'R' && player2move == 'S') || (player1move == 'S' && player2move == 'P') || (player1move == 'P' && player2move == 'R')){
        return player1;
    } else{
        return player2;
    }
}