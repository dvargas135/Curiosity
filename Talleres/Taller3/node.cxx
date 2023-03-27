#pragma once
#include "node.hpp"

template<typename T>
Node<T>::Node(T val, string attr) {
    data = val;
    height = 1;
    left = right = nullptr;
    search_attr = attr;
}
