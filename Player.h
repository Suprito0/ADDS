#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
using namespace std;

class Player{
    private:
        string name;
    public:
        virtual char makeMove() = 0;
        string getName();
};

#endif