#include "Referee.h"

Referee::Referee(){}

Player* Referee::refGame(Player* player1, Player* player2){
    char player1move = player1->makeMove();
    char player2move = player2->makeMove();

    if (player1move == player2move){
        return nullptr;
    } else if ((player1move == 'r' && player2move == 's') || (player1move == 's' && player2move == 'p') || (player1move == 'p' && player2move == 'r')){
        return player1;
    } else{
        return player2;
    }
}