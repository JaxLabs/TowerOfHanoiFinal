//
// Created by Jax on 5/17/21.
//

#ifndef TOWEROFHANOIFINAL_LINKEDLIST_H
#define TOWEROFHANOIFINAL_LINKEDLIST_H
#include <iostream>
#include "Node.h"

class LinkedList {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int _size = 0;
    void insertBefore(color item, Node* node);
    void insertAfter(color item, Node* node);
    void remove(Node* node);
    Node* search(color item);

public:
    LinkedList();
    LinkedList(const LinkedList&);
    ~LinkedList();
    LinkedList& operator = (const LinkedList& list);

    void removeTail();
    void removeHead();
    color getTailData();
    color getHeadData();
    Node* getTail();
    Node* getHead();

    void insertBefore(color item, color before);
    void insertAfter(color item, color after);
    void remove(color item);
    void push_back(color item);
    void push_front(color item);
    int size();
    bool empty();

    friend std::ostream& operator << (std::ostream& out, const LinkedList& list);

    void operator+=(Node item);
};


#endif //TOWEROFHANOIFINAL_LINKEDLIST_H
