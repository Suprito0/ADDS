#include "Node.h"

Node::Node(int data, Node *link)
{
    this->data = data;
    this->link = link;
}

Node *Node::getLink()
{
    return this->link;
}

int Node::getData()
{
    return this->data;
}

void Node::setLink(Node *link)
{
    this->link = link;
}

Node::~Node()
{
}