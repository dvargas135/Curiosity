#pragma once
#include "Node.hpp"

template<typename T>
class Edge {
public:
    // Node<T>* data;
    T data;
    Edge();
    Edge(T);
    ~Edge();
};

#include "Edge.cxx"