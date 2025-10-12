#ifndef PREFIXMATCHER_H
#define PREFIXMATCHER_H

#include "TrieNode.h"

class PrefixMatcher{
    private:
        TrieNode* head;
        TrieNode* insertHelper(string address);
    public:
        PrefixMatcher();
        int selectRouter(string networkAddress); // return the router with the longest matching prefix
        void insert(string address, int routerNumber); // add a router address
};

#endif
