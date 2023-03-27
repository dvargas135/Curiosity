#include "avltree.hpp"

template<typename T>
int AVLTree<T>::height(Node<T>* node) {
    return node == nullptr ? 0 : node->height;
}

template<typename T>
int AVLTree<T>::balanceFactor(Node<T>* node) {
    return height(node->left) - height(node->right);
}

template<typename T>
void AVLTree<T>::updateHeight(Node<T>* node) {
    node->height = 1 + std::max(height(node->left), height(node->right));
}

template<typename T>
Node<T>* AVLTree<T>::rotateLeft(Node<T>* node) {
    Node<T>* rightChild = node->right;
    Node<T>* leftSubtree = rightChild->left;
    rightChild->left = node;
    node->right = leftSubtree;
    updateHeight(node);
    updateHeight(rightChild);
    return rightChild;
}

template<typename T>
Node<T>* AVLTree<T>::rotateRight(Node<T>* node) {
    Node<T>* leftChild = node->left;
    Node<T>* rightSubtree = leftChild->right;
    leftChild->right = node;
    node->left = rightSubtree;
    updateHeight(node);
    updateHeight(leftChild);
    return leftChild;
}

template<typename T>
Node<T>* AVLTree<T>::balance(Node<T>* node) {
    updateHeight(node);
    int bf = balanceFactor(node);
    if (bf > 1 && balanceFactor(node->left) >= 0) {
        return rotateRight(node);
    }
    if (bf < -1 && balanceFactor(node->right) <= 0) {
        return rotateLeft(node);
    }
    if (bf > 1 && balanceFactor(node->left) < 0) {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (bf < -1 && balanceFactor(node->right) > 0) {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

template<typename T>
Node<T>* AVLTree<T>::insert(Node<T>* node, T val, std::string attr) {
    if (node == nullptr) {
        return new Node<T>(val, attr);
    }
    if (attr < node->search_attr) {
        node->left = insert(node->left, val, attr);
    } else {
        node->right
