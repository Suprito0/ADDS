#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <vector>
using namespace std;

class Sort{
    public:
        virtual vector<int> sort(vector<int> list) = 0;
};

#endif