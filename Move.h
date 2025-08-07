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
        string getMoveName();
        vector<string> getCanDefeat();
};

class Rock: public Move{
    public:
        Rock(){
            this->moveName = "Rock";
            canDefeat.push_back("Scissors");
        }
        
};

class Paper: public Move{
    public:
        Paper(){
            this->moveName = "Paper";
            canDefeat.push_back("Rock");
        }
        
};

class Scissors: public Move{
    public:
        Scissors(){
            this->moveName = "Scissors";
            canDefeat.push_back("Paper");
        }
        
};

class Robot: public Move{
    public:
        Robot(){
            this->moveName = "Robot";
            canDefeat.push_back("Zombie");
            canDefeat.push_back("Ninja");
        }
        
};

class Monkey: public Move{
    public:
        Monkey(){
            this->moveName = "Monkey";
            canDefeat.push_back("Robot");
            canDefeat.push_back("Ninja");
        }
        
};

class Pirate: public Move{
    public:
        Pirate(){
            this->moveName = "Pirate";
            canDefeat.push_back("Robot");
            canDefeat.push_back("Monkey");   
        }
        
};

class Ninja: public Move{
    public:
        Ninja(){
            this->moveName = "Ninja";
            canDefeat.push_back("Pirate");
            canDefeat.push_back("Zombie"); 
        }
        
};

class Zombie: public Move{
    public:
        Zombie(){
            this->moveName = "Zombie";
            canDefeat.push_back("Pirate");
            canDefeat.push_back("Monkey"); 
        }
        
};
#endif // MOVE_H