#ifndef TRIENODE_H
#define TRIENODE_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Autocomplete;
class PrefixMatcher;

class TrieNode
{
    friend class Autocomplete;
    friend class PrefixMatcher;

private:
    bool isEndofWord;
    bool isHead;
    char storedLetter;
    int routerNumber;
    vector<TrieNode *> children;

public:
    TrieNode();
    TrieNode(char storedLetter);
    void addChildren(TrieNode *child);
    void setEnd();
};

#endif
