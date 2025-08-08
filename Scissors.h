#ifndef SCISSORS_H
#define SCISSORS_H

#include "Move.h"

class Scissors : public Move{
    public:
        Scissors();
        string getName();
};

#endif // SCISSORS_H