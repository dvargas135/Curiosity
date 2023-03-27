//#ifndef AVLTREE_H
//#define AVLTREE_H
#pragma once

#include <vector>
#include <string>

#include "node.hpp"
#include "song.hpp"

template<typename T>
class AVLTree {
private:
    Node<T>* root;
    int height(Node<T>* node);
    int balanceFactor(Node<T>* node);
    void updateHeight(Node<T>* node);
    Node<T>* rotateLeft(Node<T>* node);
    Node<T>* rotateRight(Node<T>* node);
    Node<T>* balance(Node<T>* node);
    Node<T>* insert(Node<T>* node, T val, std::string attr);
    Node<T>* findMin(Node<T>* node);
    Node<T>* remove(Node<T>* node, T val, std::string attr);
    Node<T>* search(Node<T>* node, std::string attr);
    std::vector<int> getBranchHeights();
public:
    AVLTree();
    std::vector<int> getHeights();
    Node<T>* getRoot() const;
    void add(T val, std::string attr);
    void remove(T val, std::string attr);
    Node<T>* find(std::string title);
    Song nodeToSong(Node<Song>* node);
};
#include "avltree.cxx"
//#endif