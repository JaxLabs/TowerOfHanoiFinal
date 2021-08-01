//
// Created by Jax on 5/17/21.
//

#include "LinkedList.h"

LinkedList::LinkedList(): head(nullptr), tail(nullptr) {}


void LinkedList::insertBefore(color item, Node* node){//node pointer is before
    _size++;
    Node* toBeAddedNode = new Node;
    toBeAddedNode->color = item;

    if (head == nullptr){
        toBeAddedNode->next = nullptr;
        head = toBeAddedNode;
        tail = toBeAddedNode;
    }
    else if (node == head){
        toBeAddedNode->next = head;
        head = toBeAddedNode;
    }
    else if (node == tail){
        toBeAddedNode->next = tail;
        Node* walker = new Node;
        walker = head;
        while(walker->next != node){
            walker = walker->next;
        }
        walker->next = toBeAddedNode;

    }
    else{
        toBeAddedNode->next = node;

        Node* walker = new Node;
        walker = head;
        while(walker->next != node){
            walker = walker->next;
        }
        walker->next = toBeAddedNode;
    }
}


void LinkedList::insertAfter(color item, Node* node){//node pointer is after
    _size++;
    Node* toBeAddedNode = new Node;
    toBeAddedNode->color = item;
    toBeAddedNode->next = nullptr;

    if (head == nullptr){
        head = toBeAddedNode;
        tail = toBeAddedNode;
    }
    else if (node == tail){
        tail->next = toBeAddedNode;
        tail = toBeAddedNode;
    }
    else if (node == head){
        toBeAddedNode->next = head->next;
        head->next = toBeAddedNode;
    }
    else{
        toBeAddedNode->next = node->next;
        node->next = toBeAddedNode;
    }
}


void LinkedList::remove(Node* node){
    if (_size == 1){
        delete head;
        head = nullptr;
        tail = nullptr;
        _size = _size-1;
        return;
    }
    _size = _size-1;
    if (node == head){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else if (node == tail){
        Node* temp = head;
        while (temp->next != tail){
            temp = temp->next;
        }
        delete tail;
        tail = temp;
        tail->next = nullptr;
    }
    else {
        Node *joiner;
        joiner = head;
        while (joiner->next != node) {
            joiner = joiner->next;
        }
        joiner->next = node->next;
        delete node;
    }
}


Node* LinkedList::search(color item){
    Node* searcher = head;
    for(int i = 0; i<_size; i++){
        if(searcher->color == item)
            return searcher;
        searcher = searcher->next;
    }
    return nullptr;
}


void LinkedList::insertBefore(color item, color before){
    Node* node = new Node;
    node = search(before);
    insertBefore(item, node);
}


void LinkedList::insertAfter(color item, color after){
    Node* node = new Node;
    node = search(after);
    insertAfter(item, node);
}


void LinkedList::push_back(color item){
    _size++;
    if(tail == nullptr){
        tail = new Node;
        head = tail;
    }
    else{
        tail->next = new Node;
        tail = tail->next;
    }
    tail->color =  item;
    tail->next = nullptr;
}


void LinkedList::push_front(color item){
    _size++;
    if (head == nullptr) {
        head = new Node;
        head->color = item;
        head->next = nullptr;
        tail = head;
    }
    else{
        Node* nodeToBeAdded = new Node;
        nodeToBeAdded->color = item;
        nodeToBeAdded->next = head;
        head = nodeToBeAdded;
    }
}


int LinkedList::size(){
    return _size;
}


bool LinkedList::empty(){
    if (size() == 0)
        return true;
    else
        return false;
}


void LinkedList::remove(color item){
    Node* node;
    node = search(item);
    if(node != nullptr)
        remove(node);
}


void LinkedList::operator+=(Node item){
    LinkedList::push_back(item.color);
}


std::ostream& operator << (std::ostream& out, const LinkedList& list){
    Node* walker;
    int count = 1;
    walker = list.head;

    while (walker != nullptr)
    {
        out << "Node " << count << ": ";
        out << (int)walker->color << std::endl;
        walker = walker->next;
        count++;
    }
    return out;
}


LinkedList::LinkedList(const LinkedList& list) : LinkedList() {
    *this = list;
}


LinkedList::~LinkedList(){
    while(head != nullptr)
        remove(head);
    tail = nullptr;
}


LinkedList& LinkedList::operator=(const LinkedList& list){
    if (this == &list){
        return *this;
    }

    this->~LinkedList();

    Node* temp;
    temp = list.head;

    for (int i = 0; i < list._size; i++) {
        this->push_back(temp->color);
        temp = temp->next;
    }

    return *this;
}

void LinkedList::removeTail(){
    assert(!this->empty());
    remove(tail);
}

void LinkedList::removeHead(){
    assert(!this->empty());
    remove(head);
}

color LinkedList::getTailData(){
    assert(!this->empty());
    return tail->color;
}

color LinkedList::getHeadData(){
    assert(!this->empty());
    return head->color;
}

Node *LinkedList::getTail() {
    return tail;
}

Node *LinkedList::getHead() {
    return head;
}
