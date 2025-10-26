#pragma once
// DocumentManager.h
// Fast O(1)-average design using hash tables. No dynamic allocation, no raw pointers.

#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class DocumentManager {
public:
    void addDocument(const string& name, int id, int license_limit);
    void addPatron(int patronID);
    int search(string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);

private:
    struct Document {
        string name;
        int id = 0;
        int license_limit = 0;
        unordered_set<int> borrowers; 
    };
    unordered_map<int, Document> docs; 
    unordered_map<string, int> nameToID;  
    unordered_set<int> patrons;                  
};
