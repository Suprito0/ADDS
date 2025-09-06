#include <iostream>
#include <vector>
#include <string>
#include "Finder.h"

using namespace std;

int main() {
    // Example input from your practical
    string s1 = "4634554567";
    string s2 = "45689";

    Finder finder;
    vector<int> result = finder.findSubstrings(s1, s2);

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "Result indexes: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    // Additional test
    string s3 = "abcdefg";
    string s4 = "abcde";
    result = finder.findSubstrings(s3, s4);

    cout << "\nTest 2:" << endl;
    cout << "s1 = " << s3 << endl;
    cout << "s2 = " << s4 << endl;
    cout << "Result indexes: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}
