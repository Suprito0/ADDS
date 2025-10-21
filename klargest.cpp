#include<queue>
#include <vector>
#include <cmath>
using namespace std;

int kth_largest(vector<int> values, int k){
    if (k>values.size()){
        return NULL;
    }
    priority_queue<int, vector<int>, greater<int>> priorityValues;
    for (int element : values) {
        if (priorityValues.size()< k) {
            priorityValues.push(element);
        } else if (element > priorityValues.top()) {
            priorityValues.pop();
            priorityValues.push(element);
        }
    }
    return priorityValues.top();
}