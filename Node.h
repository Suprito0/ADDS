#ifndef NODE_H
#define NODE_H

#include<iostream>
using namespace std;

class Node{
    private:
        int data;
        Node* link;
    public:
        Node(int data, Node* link);
        Node* getLink();
        int getData();
        void setLink(Node* link);
        ~Node();
};

#endif