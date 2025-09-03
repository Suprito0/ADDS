#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"

int main(){
    vector<int> list;

    QuickSort quick;
    vector<int> temp = quick.sort(list);

    cout << (RecursiveBinarySearch::search(temp, 1)? "true " : "false ");
    
    for ( int i: temp){
        cout << i << " "; 
    }
    cout << endl;
}