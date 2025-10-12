#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include "TrieNode.h"

class Autocomplete
{
private:
    TrieNode *head;

public:
    Autocomplete();
    vector<string> getSuggestions(string partialWord); // return the known words that start with partialWord
    void getSuggestionsHelper(TrieNode *node, vector<string> &result, string partialWord);
    void insert(string word); // add a word to the known words
    TrieNode *insertHelper(string word);
};

#endif
