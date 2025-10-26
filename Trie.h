#pragma once
#include <map>
#include <memory>
#include <string>

using namespace std;

class NameTrie {
private:
    struct Node {
        map<char, unique_ptr<Node>> next;
        int docid = 0;
    };

    unique_ptr<Node> root;

public:
    NameTrie(): root(make_unique<Node>()) {}

    void insert( string& name, int docid) {
        Node* cur = root.get();
        for (char c : name) {
            auto it = cur->next.find(c);
            if (it == cur->next.end()) {
                auto newNode = make_unique<Node>();
                Node* raw = newNode.get();
                cur->next.emplace(c, move(newNode));
                cur = raw;
            } else {
                cur = it->second.get();
            }
        }
        cur->docid = docid;
    }

    int find(string& name)  {
        Node* cur = root.get();
        for (char c : name) {
            auto it = cur->next.find(c);
            if (it == cur->next.end()) return 0;
            cur = it->second.get();
        }
        return cur->docid;
    }
};
