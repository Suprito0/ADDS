#include "TrieNode.h"

TrieNode::TrieNode()
{
    this->isHead = true;
    this->isEndofWord = false;
    this->storedLetter = '\0';
    this->routerNumber = -1;
}

TrieNode::TrieNode(char storedLetted)
{
    this->isHead = false;
    this->isEndofWord = false;
    this->storedLetter = storedLetted;
    this->routerNumber = -1;
}

void TrieNode::addChildren(TrieNode *child)
{
    this->children.push_back(child);
}

void TrieNode::setEnd()
{
    this->isEndofWord = true;
}
