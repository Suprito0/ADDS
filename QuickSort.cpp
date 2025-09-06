#include "Sort.h"
#include "QuickSort.h"

vector<int> QuickSort::sort(vector<int> list) {
    if (list.size() <= 1) {
        return list;
    } else if (list.size() == 2){
        if (list[0] > list[1]){
            swap(list[0], list[1]);
        }
        return list;
    }

    int pivot = list[2];

    vector<int> small, equal, large;

    for (int num : list) {
        if (num < pivot) {
            small.push_back(num);
        } else if (num > pivot) {
            large.push_back(num);
        } else {
            equal.push_back(num);
        }
    }

    vector<int> sortedSmall = QuickSort::sort(small);
    vector<int> sortedLarge = QuickSort::sort(large);

    vector<int> result;
    result.insert(result.end(), sortedSmall.begin(), sortedSmall.end());
    result.insert(result.end(), equal.begin(), equal.end());
    result.insert(result.end(), sortedLarge.begin(), sortedLarge.end());

    return result;
}
