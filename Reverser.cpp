#include"Reverser.h"

int Reverser::reverseDigit(int value){
    if (value < 10){
        return value;
    }
    else {
        int s = pow(10,log10(value));
        return  10 * reverseDigit(value%s) + value/ s;

    }
}

string Reverser::reverseString(string characters){
    if (sizeof(characters) == 1) {
        return characters;
    }
}