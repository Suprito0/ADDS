#include"Move.h"

string Move::getName(){
    return this->moveName;
}
vector<string> Move::getCanDefeat(){
    return this->canDefeat;
}