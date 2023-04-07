#include "quadtree.hpp"
#include <queue>

QuadTree::QuadTree() : root(nullptr) {}

QuadTree::QuadTree(Point val) {
    root = new QuadNode(val);
}

QuadTree::~QuadTree() {
    deleteSubtree(root);
}

void QuadTree::deleteSubtree(QuadNode* node) {
    if (node) {
        deleteSubtree(node->getSuperiorLeftChild());
        deleteSubtree(node->getSuperiorRightChild());
        deleteSubtree(node->getInferiorLeftChild());
        deleteSubtree(node->getInferiorRightChild());
        delete node;
    }
}

Point QuadTree::rootData() {
    if (root) {
        return root->getData();
    } else {
        std::cerr << "Error: QuadTree is empty." << std::endl;
        return Point();
    }
}

QuadNode* QuadTree::getRoot() {
    return root;
}

void QuadTree::setRoot(QuadNode* rootNode) {
    root = rootNode;
}

bool QuadTree::isEmpty() {
    return root == nullptr;
}

bool QuadTree::insert(Point val) {
    if (isEmpty()) {
        root = new QuadNode(val);
        return true;
    } else {
        return insert(val, root);
    }
}

bool QuadTree::insert(Point val, QuadNode* node) {
    if (node->isLeaf()) {
        QuadNode* newNode = new QuadNode(val);
        if (val == node->getData()) {
            delete newNode;
            return false;
        } else {
            subdivide(node);
            insert(val, node);
        }
    } else {
        if (val == node->getData()) {
            return false;
        } else {
            if (val.x < node->getData().x) {
                if (val.y < node->getData().y) {
                    return insert(val, node->getInferiorLeftChild());
                } else {
                    return insert(val, node->getSuperiorLeftChild());
                }
            } else {
                if (val.y < node->getData().y) {
                    return insert(val, node->getInferiorRightChild());
                } else {
                    return insert(val, node->getSuperiorRightChild());
                }
            }
        }
    }
}

void QuadTree::subdivide(QuadNode* node) {
    Point center = node->getData();
    int x = center.x;
    int y = center.y;
    node->setInferiorLeftChild(new QuadNode(Point(x - 1, y - 1)));
    node->setInferiorRightChild(new QuadNode(Point(x + 1, y - 1)));
    node->setSuperiorLeftChild(new QuadNode(Point(x - 1, y + 1)));
    node->setSuperiorRightChild(new QuadNode(Point(x + 1, y + 1)));
}

void QuadTree::preOrder() {
    preOrder(root);
}

void QuadTree::preOrder(QuadNode* node) {
    if (node) {
        std::cout << node->getData() << " ";
        preOrder(node->getSuperiorLeftChild());
        preOrder(node->getSuperiorRightChild());
        preOrder(node->getInferiorLeftChild());
        preOrder(node->getInferiorRightChild());
    }
}

void QuadTree::inOrder() {
    inOrder(root);
}

void QuadTree::inOrder(QuadNode* node) {
    if (node) {
        inOrder(node->getSuperiorLeftChild());
        std::cout << node->getData() << " ";
        inOrder(node->getSuperiorRightChild());
        inOrder(node->getInferiorLeftChild());
        inOrder(node->getInferiorRightChild());
    }
}

void QuadTree::levelOrder() {
    if (root == nullptr) {
        return;
    }
    std::queue<QuadNode*> q;
    q.push(root);
    while (!q.empty()) {
        QuadNode* current = q.front();
        std::cout << current->getData() << " ";
        q.pop();
        if (current->getSuperiorLeftChild() != nullptr) {
            q.push(current->getSuperiorLeftChild());
        }
        if (current->getSuperiorRightChild() != nullptr) {
            q.push(current->getSuperiorRightChild());
        }
        if (current->getInferiorLeftChild() != nullptr) {
            q.push(current->getInferiorLeftChild());
        }
        if (current->getInferiorRightChild() != nullptr) {
            q.push(current->getInferiorRightChild());
        }
    }
    std::cout << std::endl;
}

bool QuadTree::isEmpty() {
    return root == nullptr;
}