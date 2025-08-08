#ifndef MOVE_H
#define MOVE_H

#include<iostream>
using namespace std;
#include<vector>

class Player;

class Move{
    protected:
        vector<string> canDefeat;
        string moveName;
    public:

        virtual string getName() = 0;
        vector<string> getCanDefeat();
        static Player* play(Player* player1, Player* player2);

};

#endif // MOVE_H