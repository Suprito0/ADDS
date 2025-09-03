#include "BubbleSort.h"
#include "QuickSort.h"
#include "RecursiveBinarySearch.h"
#include <sstream>

int main(){
    std::vector<int> list;
    std::string input;
    std::getline(std::cin, input);
    std::istringstream iss(input);
    for (int x; iss >> x;) list.push_back(x);

    QuickSort quick;
    vector<int> temp = quick.sort(list);

    cout << (RecursiveBinarySearch::search(temp, 1)? "true " : "false ");

    for ( int i: temp){
        cout << i << " "; 
    }
    cout << endl;
}