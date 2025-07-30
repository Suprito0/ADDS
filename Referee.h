#ifndef REFEREE_H
#define REFEREE_H

#include "Human.h"
#include "Computer.h"

class Referee{
    public:
        Referee( ); // constructor
        Player * refGame(Player * player1, Player * player2);
};

#endif