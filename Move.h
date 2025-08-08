#ifndef MOVE_H
#define MOVE_H

#include<iostream>
using namespace std;
#include<vector>

class Move{
    protected:
        vector<string> canDefeat;
        string moveName;
    public:

        virtual string getName() = 0;
        vector<string> getCanDefeat();
};

#endif // MOVE_H