#pragma once
#include <map>
#include <memory>
#include <string>

using namespace std;

class Trie {
private:
    struct Node {
        map<char, unique_ptr<Node>> next;
        int docid = 0;
    };

    unique_ptr<Node> root;

public:
    Trie();
    void insert(string& name, int docid);
    int find(string& name);
};
