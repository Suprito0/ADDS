#pragma once
#include <map>  
#include <set>      
#include <string>
#include "Trie.h"

class DocumentManager {
public:
    void addDocument(string name, int id, int license_limit);
    void addPatron(int patronID);
    int  search(string name);
    bool borrowDocument(int docid, int patronID);
    void returnDocument(int docid, int patronID);

private:
    struct Document {
        int id = 0;
        int license_limit = 0;
        set<int> borrowers;
    };

    map<int, Document> docsById;

    NameTrie nameIndex;

    set<int> patrons;
};
