#pragma once
#include "Node.hpp"

template<typename T>
Node<T>::Node(T data, double cost)
    : data(data), cost(cost), next(nullptr) {}

template<typename T>
Node<T>::Node() {}

template<typename T>
Node<T>::~Node() {
    Node<T>* current = this;
    while (current) {
        Node<T>* nextNode = current->next;
        delete current;
        current = nextNode;
    }
}
