#include "BubbleSort.h"

int main(){
    vector<int> list = {3,2,4,5,6,1,7,9,8};
    vector<int> temp = BubbleSort::sort(list);

    for (int num: temp){
        cout << num << endl;
    }
}