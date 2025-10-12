#include "PrefixMatcher.h"

PrefixMatcher::PrefixMatcher(){
    this->head = new TrieNode();
}

TrieNode* PrefixMatcher::insertHelper(string address){
    int n = address.length();
    if(n == 0){ return this->head; }

    string prev = address;
    TrieNode* parent;
    TrieNode* child;
    char toAdd;

    if(n > 1){
        prev.pop_back();
        parent = PrefixMatcher::insertHelper(prev);
        toAdd = address.at(n - 1);
        for(TrieNode* node : parent->children){
            if(node->storedLetter == toAdd){
                return node;
            }
        }
        child = new TrieNode(toAdd);
        parent->addChildren(child);
        return child;
    } else {
        toAdd = address[0];
        for(TrieNode* node : this->head->children){
            if(node->storedLetter == toAdd){
                return node;
            }
        }
        parent = new TrieNode(toAdd);
        this->head->addChildren(parent);
        return parent;
    }
}

void PrefixMatcher::insert(string address, int routerNumber){
    if(address.empty()){ return; }
    TrieNode* tail = PrefixMatcher::insertHelper(address);
    tail->setEnd();
    tail->routerNumber = routerNumber;
}

int PrefixMatcher::selectRouter(string networkAddress){
    TrieNode* node = this->head;
    int best = -1; 

    if(node->isEndofWord && node->routerNumber >= 0){
        best = node->routerNumber;
    }

    for(char bit : networkAddress){
        bool found = false;
        for(TrieNode* child : node->children){
            if(child->storedLetter == bit){
                node = child;
                found = true;
                if(node->isEndofWord && node->routerNumber >= 0){
                    best = node->routerNumber; 
                }
                break;
            }
        }
        if(!found){ break; } 
    }
    return best;
}
