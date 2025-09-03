#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main(){
    vector<int> list = {3,2,4,5,6,7,9,8,6,5,6,7,8,5,3,67,8,56,32,42,66675,532,4,321};
    QuickSort quick;
    vector<int> temp = quick.sort(list);
    if(RecursiveBinarySearch::search(temp, 1)){
        cout << "true ";
    } else {
        cout << "false ";
    }
    for ( int i: temp){
        cout << i << " "; 
    }
    cout << endl;
}