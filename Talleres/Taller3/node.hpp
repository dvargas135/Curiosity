//#ifndef NODE_H
//#define NODE_H
#pragma once

#include <string>

using namespace std;

template<typename T>
class Node {
public:
    T data;
    int height;
    string search_attr;
    Node<T>* left;
    Node<T>* right;

    Node(T val, string attr);
};
#include "node.cxx"
//#endif