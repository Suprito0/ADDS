#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
using namespace std;
class Move;

class Player{
    public:
        string name;
        virtual Move* makeMove() = 0;
        string getName();
};

#endif