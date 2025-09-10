#include "LinkedList.h"
#include <limits>

LinkedList::LinkedList()
{
    this->head = nullptr;
    this->len = 0;
}
LinkedList::LinkedList(int *array, int len)
{
    Node *ptr = nullptr;
    for (int i = len - 1; i >= 0; i--)
    {
        ptr = new Node(*(array + i), ptr);
    }
    this->head = ptr;
    this->len = len;
}
void LinkedList::insertPosition(int pos, int newNum)
{
    if (pos <= 1)
    {
        pos = 1;
    }
    else if (pos > this->len)
    {
        pos = len + 1;
    }
    if (pos == 1)
    {
        this->head = new Node(newNum, this->head);
    }
    else
    {
        this->getNode(pos - 1)->setLink(new Node(newNum, this->getNode(pos)));
    }
    this->len++;
}
bool LinkedList::deletePosition(int pos)
{
    if (pos > this->len || pos < 1)
        return false;

    Node *toBeDeleted;
    if (pos == 1)
    {
        toBeDeleted = this->head;
        this->head = this->head->getLink();
    }
    else
    {
        Node *prev = this->getNode(pos - 1);
        toBeDeleted = prev->getLink();
        prev->setLink(toBeDeleted->getLink());
    }
    delete toBeDeleted;
    this->len--;
    return true;
}

int LinkedList::get(int pos)
{
    Node *node = this->getNode(pos);
    return node ? node->getData() : numeric_limits<int>::max();
}

Node *LinkedList::getNode(int pos)
{
    if (pos > this->len || pos < 1)
        return nullptr;

    Node *link = this->head;
    for (int i = 1; i < pos; i++)
    {
        link = link->getLink();
    }
    return link;
}

void LinkedList::setHead(Node *link)
{
    this->head = link;
}

int LinkedList::search(int target)
{
    Node *link = this->head;
    int pos = 1;
    while (link)
    {
        if (link->getData() == target)
            return pos;
        link = link->getLink();
        pos++;
    }
    return -1;
}

void LinkedList::printList()
{
    if (len == 0)
    {
        return;
    }
    Node *link = this->head;
    cout << "[";
    for (int i = 1; i <= this->len - 1; i++)
    {
        cout << link->getData() << " ";
        link = link->getLink();
    }
    cout << link->getData() << "]" << endl;
}
LinkedList::~LinkedList()
{
    Node *link = this->head;
    while (link)
    {
        Node *temp = link;
        link = link->getLink();
        delete temp;
    }
}
