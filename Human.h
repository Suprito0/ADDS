#ifndef HUMAN_H
#define HUMAN_H

#include "Player.h"

class Human : public Player{
    public:
        Human();
        Human(string name);
        Move* makeMove();
};

#endif