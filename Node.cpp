#include"Node.h"

Node::Node(int data, Node* link){
    this->data = data;
    this->link = link;
}

void Node::inPtr(Node* link){
    this->link = link;
}