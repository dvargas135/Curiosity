#include "quadtree.hpp"
#include <queue>
#include "../classes/element.hpp"
#include <vector>
using namespace std;

QuadTree::QuadTree() {
    root = nullptr;
}

QuadTree::QuadTree(Point val) {
    root = new QuadNode(val);
}

QuadTree::~QuadTree() {
    deleteSubtree(root);
}

void QuadTree::deleteSubtree(QuadNode* node) {
    if (node != nullptr) {
        deleteSubtree(node->getSuperiorLeftChild());
        deleteSubtree(node->getSuperiorRightChild());
        deleteSubtree(node->getInferiorLeftChild());
        deleteSubtree(node->getInferiorRightChild());
        delete node;
    }
}

Point QuadTree::rootData() {
    if (root != nullptr) {
        return root->getData();
    } else {
        std::cerr << "Error: root is null." << std::endl;
        return Point{0, 0};
    }
}

QuadNode* QuadTree::getRoot() {
    return root;
}

void QuadTree::setRoot(QuadNode* rootNode) {
    root = rootNode;
}

bool QuadTree::isEmpty() {
    return (root == nullptr);
}

bool QuadTree::insert(Point& val) {
    QuadNode* newNode = new QuadNode(val);

    if (root == nullptr) {
        root = newNode;
        return true;
    } else {
        QuadNode* currentNode = root;

        while (true) {
            if (currentNode->getData() == val) {
                delete newNode;
                return false;
            }

            if (val.x < currentNode->getData().x) {
                if (val.y < currentNode->getData().y) {
                    if (currentNode->getInferiorLeftChild() == nullptr) {
                        currentNode->setInferiorLeftChild(newNode);
                        return true;
                    } else {
                        currentNode = currentNode->getInferiorLeftChild();
                    }
                } else {
                    if (currentNode->getSuperiorLeftChild() == nullptr) {
                        currentNode->setSuperiorLeftChild(newNode);
                        return true;
                    } else {
                        currentNode = currentNode->getSuperiorLeftChild();
                    }
                }
            } else {
                if (val.y < currentNode->getData().y) {
                    if (currentNode->getInferiorRightChild() == nullptr) {
                        currentNode->setInferiorRightChild(newNode);
                        return true;
                    } else {
                        currentNode = currentNode->getInferiorRightChild();
                    }
                } else {
                    if (currentNode->getSuperiorRightChild() == nullptr) {
                        currentNode->setSuperiorRightChild(newNode);
                        return true;
                    } else {
                        currentNode = currentNode->getSuperiorRightChild();
                    }
                }
            }
        }
    }
}

void QuadTree::preOrder(QuadNode* root) {
    if (root != nullptr) {
        std::cout << root->getData() << " ";
        preOrder(root->getSuperiorLeftChild());
        preOrder(root->getSuperiorRightChild());
        preOrder(root->getInferiorLeftChild());
        preOrder(root->getInferiorRightChild());
    }
}

vector<Point> QuadTree::listaPreorder(QuadNode* root,double x1, double x2, double y1, double y2,vector<Point> puntos){
    
    if (root != nullptr) {
        if(root->getData().x>x1 && root->getData().x<x2 && root->getData().y>y1 && root->getData().y<y2){
        puntos.push_back(root->getData());}
        puntos=listaPreorder(root->getSuperiorLeftChild(),x1,x2,y1,y2,puntos);
        puntos=listaPreorder(root->getSuperiorRightChild(),x1,x2,y1,y2,puntos);
        puntos=listaPreorder(root->getInferiorLeftChild(),x1,x2,y1,y2,puntos);
        puntos=listaPreorder(root->getInferiorRightChild(),x1,x2,y1,y2,puntos);
    
    }
    return puntos;
}


void QuadTree::preOrder() {
    preOrder(root);
}

void QuadTree::inOrder(QuadNode* root) {
    if (root != nullptr) {
        inOrder(root->getSuperiorLeftChild());
        std::cout << root->getData() << " ";
        inOrder(root->getSuperiorRightChild());
        inOrder(root->getInferiorLeftChild());
        inOrder(root->getInferiorRightChild());
    }
}

void QuadTree::inOrder() {
    inOrder(root);
}

void QuadTree::postOrder(QuadNode* root) {
    if (root != nullptr) {
        postOrder(root->getSuperiorLeftChild());
        postOrder(root->getSuperiorRightChild());
        postOrder(root->getInferiorLeftChild());
        postOrder(root->getInferiorRightChild());
        std::cout << root->getData() << " ";
    }
}

void QuadTree::postOrder() {
    postOrder(root);
}

void QuadTree::levelOrder() {
    if (root != nullptr) {
        std::queue<QuadNode*> q;
        q.push(root);

        while (!q.empty()) {
            QuadNode* current = q.front();
            q.pop();

            std::cout << current->getData() << " ";

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
    }
}