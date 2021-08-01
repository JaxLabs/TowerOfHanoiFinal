//
// Created by Jax on 5/17/21.
//

#include "Stack.h"
void Stack::push(color item){

    list.push_back(item);
}

color Stack::pop(){
    Node* temp = list.getTail();

    list.removeTail();
    return temp->color;
}

Node* Stack::top(){
    return list.getTail();
}

bool Stack::empty(){
    return list.empty();
}

int Stack::size(){
    return list.size();
}

bool Stack::invalid(Node item){
    if (list.empty()){
        return false;
    }
    if (item.color == color::RED && list.getTailData() == color::ORANGE)
        return false;
    else if ((item.color == color::RED ||
            item.color == color::ORANGE) &&
            list.getTailData() == color::YELLOW)
        return false;
    else if ((item.color == color::RED ||
              item.color == color::ORANGE ||
              item.color == color::YELLOW) &&
            list.getTailData() == color::GREEN)
        return false;
    else
        return true;
}

Stack::~Stack(){
    while(list.getHead() != nullptr)
        pop();
}

int Stack::getId() const {
    return id;
}

void Stack::setId(int id) {
    Stack::id = id;
}
