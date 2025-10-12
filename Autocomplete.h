#ifndef AUTOCOMPLETE_H
#define AUTOCOMPLETE_H

#include"TrieNode.h"

class Autocomplete{
    private:
        TrieNode head;
    public:
        vector<string> getSuggestions(string partialWord);  // return the known words that start with partialWord
        void insert(string word); // add a word to the known words
};

#endif