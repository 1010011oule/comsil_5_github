#ifndef STACK_H
#define STACK_H

#include "LinkedList.h"

template <typename T>
class Stack : public LinkedList<T> {
public:
    bool Delete(T &element) override {
        if (this->first == NULL)
            return false;

        Node<T>* temp = this->first;
        element = temp->data;
        this->first = this->first->link;
        delete temp;
        
        this->current_size--;
        return true;
    }
};

#endif

