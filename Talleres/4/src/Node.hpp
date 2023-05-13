#pragma once

template<typename T>
class Node {
public:
    T* data;
    double cost;
    Node<T>* next;

    Node(T*, double);
    Node();
    ~Node();
};

#include "Node.cxx"