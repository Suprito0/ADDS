#include "Sort.h"
#include "QuickSort.h"

vector<int> QuickSort::sort(vector<int> list) {
    if (list.size() <= 1) {
        return list;
    } else if (list.size() == 2) {
        if (list[0] > list[1]) {
            swap(list[0], list[1]);
        }
        return list;
    }

    int pivotIndex = 2;
    int pivot = list[pivotIndex];

    vector<int> small, large;

    for (int i = 0; i < list.size(); i++) {
        if (i == pivotIndex) continue;
        if (list[i] < pivot) {
            small.push_back(list[i]);
        } else {
            large.push_back(list[i]);
        }
    }

    vector<int> sortedSmall = QuickSort::sort(small);
    vector<int> sortedLarge = QuickSort::sort(large);

    vector<int> result;
    result.insert(result.end(), sortedSmall.begin(), sortedSmall.end());
    result.push_back(pivot);
    result.insert(result.end(), sortedLarge.begin(), sortedLarge.end());

    return result;
}