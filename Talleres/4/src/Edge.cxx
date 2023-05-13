#pragma once
#include "Edge.hpp"

template<typename T>
Edge<T>::Edge(T* data)
    : data(data) {}

template<typename T>
Edge<T>::Edge() {}