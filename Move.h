#include<iostream>
using namespace std;

class Move{
    public:
        virtual string get_moveName() = 0;
};

class Rock: public Move{
    public:
        string get_moveName();
};

class Paper: public Move{
    public:
        string get_moveName();
};

class Scissors: public Move{
    public:
        string get_moveName();
};

class Robot: public Move{
    public:
        string get_moveName();
};

class Monkey: public Move{
    public:
        string get_moveName();
};

class Pirate: public Move{
    public:
        string get_moveName();
};

class Ninja: public Move{
    public:
        string get_moveName();
};

class Zombie: public Move{
    public:
        string get_moveName();
};