#include"Autocomplete.h"

Autocomplete::Autocomplete(){}
vector<string> Autocomplete::getSuggestions(string partialWord){
    vector<string> d;
    return d;
}
TrieNode* Autocomplete::insertHelper(string word){
    int numOfLetters = word.length();
    string tempWord = word;
    TrieNode* temp1;
    TrieNode* temp2;
    char letterToAdd;
    if(numOfLetters>1){
        tempWord.pop_back();
        temp1 = Autocomplete::insertHelper(tempWord);
        letterToAdd = word.at(numOfLetters-1);
        for(TrieNode* node: temp1->children){
            if(node->storedLetter == letterToAdd){
                return node;
            }
        }
        temp2 = new TrieNode(letterToAdd);
        temp1->addChildren(temp2);
        return temp2;
    } else{
        letterToAdd = word[0];
        for(TrieNode* node: head->children){
            if(node->storedLetter == letterToAdd){
                return node;
            }
        }
        temp1 = new TrieNode(letterToAdd);
        this->head->addChildren(temp1);
        return temp1;
    }
}

void Autocomplete::insert(string word){
    TrieNode* tail = insertHelper(word);
    tail->setEnd();
}