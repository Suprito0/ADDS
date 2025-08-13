#include"Reverser.h"

int Reverser::reverseDigit(int value){
    int count = log10(value);
    cout << "Count: " << count << endl;
    if (value < 10){
        return value;
    }
    else {
        int s = pow(10,count);
        return  10 * reverseDigit(value%s) + value/ s;

    }
}
