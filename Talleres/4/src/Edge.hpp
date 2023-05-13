#pragma once

template<typename T>
class Edge {
public:
    T* data;
    Edge();
    Edge(T*);
};

#include "Edge.cxx"