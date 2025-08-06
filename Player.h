#ifndef PLAYER_H
#define PLAYER_H

#include"Move.h"
#include<iostream>
using namespace std;

class Player{
    public:
        string name;
        virtual Move* makeMove() = 0;
        string getName();
};

#endif