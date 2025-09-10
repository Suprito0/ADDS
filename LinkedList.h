#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

class LinkedList
{
private:
    Node *head;
    int len;

public:
    LinkedList();
    LinkedList(int *array, int len);
    void insertPosition(int pos, int newNum);
    bool deletePosition(int pos);
    int get(int pos);
    Node *getNode(int pos);
    void setHead(Node *link);
    void setLen(int len);
    int search(int target);
    void printList();
    ~LinkedList();
};

#endif