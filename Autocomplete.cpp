#include "Autocomplete.h"

Autocomplete::Autocomplete()
{
    this->head = new TrieNode();
}

TrieNode *Autocomplete::insertHelper(string word)
{
    int numOfLetters = word.length();
    string tempWord = word;
    TrieNode *temp1;
    TrieNode *temp2;
    char letterToAdd;

    if (numOfLetters > 1)
    {
        tempWord.pop_back();
        temp1 = Autocomplete::insertHelper(tempWord);
        letterToAdd = word.at(numOfLetters - 1);
        for (TrieNode *node : temp1->children)
        {
            if (node->storedLetter == letterToAdd)
            {
                return node;
            }
        }
        temp2 = new TrieNode(letterToAdd);
        temp1->addChildren(temp2);
        return temp2;
    }
    else
    {
        letterToAdd = word[0];
        for (TrieNode *node : this->head->children)
        {
            if (node->storedLetter == letterToAdd)
            {
                return node;
            }
        }
        temp1 = new TrieNode(letterToAdd);
        this->head->addChildren(temp1);
        return temp1;
    }
}

void Autocomplete::insert(string word)
{
    if (word.empty())
    {
        return;
    }
    TrieNode *tail = Autocomplete::insertHelper(word);
    tail->setEnd();
}

void Autocomplete::getSuggestionsHelper(TrieNode *node, vector<string> &result, string partialWord)
{
    if (node->isEndofWord)
    {
        result.push_back(partialWord);
    }
    for (TrieNode *tempNode : node->children)
    {
        string nextWord = partialWord + tempNode->storedLetter;
        Autocomplete::getSuggestionsHelper(tempNode, result, nextWord);
    }
}

vector<string> Autocomplete::getSuggestions(string partialWord)
{
    int numOfLetters = partialWord.length();
    TrieNode *node = this->head;
    vector<string> result;

    for (int i = 0; i < numOfLetters; i++)
    {
        bool found = false;
        for (TrieNode *tempNode : node->children)
        {
            if (tempNode->storedLetter == partialWord[i])
            {
                node = tempNode;
                found = true;
                break;
            }
        }
        if (!found)
        {
            return result;
        }
    }

    Autocomplete::getSuggestionsHelper(node, result, partialWord);
    return result;
}
