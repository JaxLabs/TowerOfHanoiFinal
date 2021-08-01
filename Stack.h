//
// Created by Jax on 5/17/21.
//

#ifndef TOWEROFHANOIFINAL_STACK_H
#define TOWEROFHANOIFINAL_STACK_H
#include "Node.h"
#include "LinkedList.h"

class Stack {
public:
    ~Stack();
    void push(color item);
    color pop();
    Node* top();
    bool empty();
    int size();
    bool invalid(Node item);

private:
    LinkedList list;
    int id;
public:
    int getId() const;
    void setId(int id);
};


#endif //TOWEROFHANOIFINAL_STACK_H
