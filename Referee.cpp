#include "Referee.h"

Referee::Referee(){}

Player* Referee::refGame(Player* player1, Player* player2){
    return Move::play(player1, player2);
}