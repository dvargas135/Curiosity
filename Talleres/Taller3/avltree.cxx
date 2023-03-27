#pragma once
#include "avltree.hpp"

template<typename T>
AVLTree<T>::AVLTree() {
    root = nullptr;
}
template<typename T>
vector<int> AVLTree<T>::getHeights() {
    return getBranchHeights();
}
template<typename T>
Node<T>* AVLTree<T>::getRoot() const {
    return root;
}
template<typename T>
void AVLTree<T>::add(T val, string attr) {
    root = insert(root, val, attr);
}
template<typename T>
void AVLTree<T>::remove(T val, string attr) {
    root = remove(root, val, attr);
}
template<typename T>
Node<T>* AVLTree<T>::find(string title) {
    return search(root, title);
}
template<typename T>
Song AVLTree<T>::nodeToSong(Node<Song>* node) {
    return node->data;
}

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
        node->right = insert(node->right, val, attr);
    }
    return balance(node);
}

template<typename T>
Node<T>* AVLTree<T>::findMin(Node<T>* node) {
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

template<typename T>
Node<T>* AVLTree<T>::remove(Node<T>* node, T val, std::string attr) {
    if (node == nullptr) {
        return node;
    }
    if (attr < node->search_attr) {
        node->left = remove(node->left, val, attr);
    } else if (attr > node->search_attr) {
        node->right = remove(node->right, val, attr);
    } else {
        Node<T>* leftChild = node->left;
        Node<T>* rightChild = node->right;
        delete node;
        if (rightChild == nullptr) {
            return leftChild;
        }
        Node<T>* minNode = findMin(rightChild);
        minNode->right = remove(rightChild, minNode->data, attr);
        minNode->left = leftChild;
        return balance(minNode);
    }
    return balance(node);
}

template<typename T>
Node<T>* AVLTree<T>::search(Node<T>* node, std::string attr) {
    if (node == nullptr || node->search_attr == attr) {
        return node;
    }
    if (attr < node->search_attr) {
        return search(node->left, attr);
    } else {
        return search(node->right, attr);
    }
}
template<typename T>
vector<int> AVLTree<T>::getBranchHeights() {
    vector<int> branchHeights;
    if (root) {
        vector<Node<T>*> stack;
        stack.push_back(root);
        while (!stack.empty()) {
            Node<T>* node = stack.back();
            stack.pop_back();
            if (!node->left && !node->right) {
                branchHeights.push_back(node->height);
            } else {
                if (node->left) {
                    stack.push_back(node->left);
                }
                if (node->right) {
                    stack.push_back(node->right);
                }
            }
        }
    }
    return branchHeights;
}