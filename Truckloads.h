#ifndef TRUCKLOADS_H
#define TRUCKLOADS_H

#include<iostream>
#include<vector>
using namespace std;

class Truckloads{
    private:
        vector<int> piles;
    public:
        static int numTrucks(int numCrates, int loadSize);
};

#endif