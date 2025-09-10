#include"LinkedList.h"
#include<limits>

LinkedList::LinkedList(){
    this->head = nullptr;
}
LinkedList::LinkedList(int* array, int len){
    Node* ptr = nullptr;
    for(int i=len -1; i>=1; i--){
        ptr = new Node(*(array + i), ptr);
    }
    this->head = ptr;
    this->len = len;
}
void LinkedList::insertPosition(int pos, int newNum){
    if (pos <=1){
        pos = 1;
    } else if (pos>this->len){
        pos = len + 1;
    }
    if(pos == 1){
        this->head = new Node(newNum, this->getNode(1));
    } else {
        this->getNode(pos-1)->setLink(new Node(newNum, this->getNode(pos)));
    }

}
bool LinkedList::deletePosition(int pos){
    if(pos>this->len || pos < 1) return false;
    Node* beforeDeleted = this->getNode(pos-1);
    Node* toBeDeleted = this->getNode(pos);
    Node* afterDeleted = this->getNode(pos+1);
    if(!afterDeleted){
        beforeDeleted->setLink(nullptr);
    } 
    if(!beforeDeleted){
        this->setHead(afterDeleted);
    }
    if(afterDeleted && beforeDeleted){
        beforeDeleted->setLink(afterDeleted);
    }
    delete toBeDeleted;
    this->len = len-1;
    return true;
}
int LinkedList::get(int pos){
    if(pos>this->len || pos < 1) return numeric_limits<int>::max();

    Node* link = this->head;
    for (int i=1; i<pos; i++){
        link = link->getLink();
    }
    return link->getData();
}

Node* LinkedList::getNode(int pos){
    if(pos>this->len || pos < 1) return nullptr;

    Node* link = this->head;
    for (int i=1; i<pos; i++){
        link = link->getLink();
    }
    return link;
}

void LinkedList::setHead(Node* link){
    this->head = link;
}

int LinkedList::search(int target){
    for(int i = 1; i<=len; i++){
        if(this->get(i) == target){
            return i;
        }
    }
    return -1;
}
void LinkedList::printList(){
    if(len == 0){
        return;
    }
    Node* link = this->head;
    cout << "[";
    for(int i=1; i<=this->len -1; i++){
        cout << link->getData() << " ";
        link = link->getLink();
    }
        cout << link->getData() << "]" << endl;
}
LinkedList::~LinkedList(){
    Node* link = this->head;
    Node* temp;
    for(int i=1; i<=this->len; i++){
        temp = link;
        link = link->getLink();
        delete temp->getLink();
    }
}