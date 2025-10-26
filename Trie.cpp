#include "Trie.h"

Trie::Trie(){
    this->root = make_unique<Node>();
}

void Trie::insert(string& name, int docid) {
    Node* current = root.get();
    for (char c : name) {
        auto it = current->next.find(c);
        if (it == current->next.end()) {
            auto newNode = make_unique<Node>();
            Node* raw = newNode.get();
            current->next.emplace(c, move(newNode));
            current = raw;
        } else {
            current = it->second.get();
        }
    }
    current->docid = docid;
}

int Trie::find(string& name)  {
    Node* current = root.get();
    for (char c : name) {
        auto it = current->next.find(c);
        if (it == current->next.end()) return 0;
        current = it->second.get();
    }
    return current->docid;
}