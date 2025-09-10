#include"LinkedList.h"

LinkedList::LinkedList(){
    this->head = nullptr;
}
LinkedList::LinkedList(int* array, int len){
    for(int i=len -1; i>=1; i--){
        new Node(*(array + i), nullptr);
    }

}
void LinkedList::insertPosition(int pos, int newNum);
bool LinkedList::deletePosition(int pos);
int LinkedList::get(int pos);
int LinkedList::search(int target);
void LinkedList::printList();
LinkedList::~LinkedList();