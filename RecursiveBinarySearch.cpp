#include "RecursiveBinarySearch.h"

bool RecursiveBinarySearch::search(vector<int> list, int num){
    int midNum, midIndex;
    if(list.size() <= 2){
        for (int temp: list){
            if (temp == num){
                return true;
            } 
        }
        return false;
    }

    midIndex = list.size()/2;
    midNum = list[midIndex];

    vector<int> tempVec;

    if(midNum == num){
        return true;
    } else if (midNum > num){
        tempVec.assign(list.begin(), list.begin() + midIndex);
    } else {
        tempVec.assign(list.begin() + midIndex + 1, list.end());
    }
    return RecursiveBinarySearch::search(tempVec, num);
}