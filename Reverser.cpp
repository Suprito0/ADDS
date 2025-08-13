#include"Reverser.h"

int Reverser::reverseDigit(int value){
    int count = log10(value);
    if (value < 10){
        return value;
    }
    else {
        int s = pow(10,count);
        return  10 * reverseDigit(value%s) + value/ s;

    }
}

string Reverser::reverseString(string characters){
    int length = characters.length();
    if (length == 1) {
        return characters;
    } else {
        return characters[length - 1] + reverseString(characters.substr(0, length - 1));
        
    }
}