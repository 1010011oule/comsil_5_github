#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* link;

    Node(T element) {
        data = element;
        link = NULL;
    }
};

template <typename T>
class LinkedList {
protected:
    Node<T>* first;
    int current_size;

public:
    LinkedList() {
        first = NULL;
        current_size = 0;
    }

    int GetSize() const {
        return current_size;
    }

    void Insert(T element);
    virtual bool Delete(T &element);
    void Print() const;
};

template <typename T>
void LinkedList<T>::Insert(T element) {
    Node<T>* newNode = new Node<T>(element);
    newNode->link = first;
    first = newNode;
    current_size++;
}

template <typename T>
bool LinkedList<T>::Delete(T &element) {
    if (first == NULL)
        return false;

    Node<T>* current = first;
    Node<T>* previous = NULL;

    while (current->link != NULL) {
        previous = current;
        current = current->link;
    }

    if (previous)
        previous->link = NULL;
    else
        first = NULL;

    element = current->data;
    delete current;
    current_size--;

    return true;
}

template <typename T>
void LinkedList<T>::Print() const {
    Node<T>* temp = first;
    int index = 1;

    while (temp != NULL) {
        std::cout << "[" << index << "|" << temp->data << "]";
        if (temp->link != NULL)
            std::cout << " -> ";
        
        temp = temp->link;
        index++;
    }

    std::cout << std::endl;
}

#endif

