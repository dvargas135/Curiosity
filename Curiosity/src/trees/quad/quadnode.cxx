#include "quadnode.hpp"

QuadNode::QuadNode() {
    superiorLeftChild = nullptr;
    superiorRightChild = nullptr;
    inferiorLeftChild = nullptr;
    inferiorRightChild = nullptr;
}

QuadNode::QuadNode(Point val) {
    data = val;
    superiorLeftChild = nullptr;
    superiorRightChild = nullptr;
    inferiorLeftChild = nullptr;
    inferiorRightChild = nullptr;
}

QuadNode::~QuadNode() {
    delete superiorLeftChild;
    delete superiorRightChild;
    delete inferiorLeftChild;
    delete inferiorRightChild;
}

Point QuadNode::getData() {
    return data;
}

void QuadNode::setData(Point val) {
    data = val;
}

QuadNode* QuadNode::getSuperiorLeftChild() {
    return superiorLeftChild;
}

QuadNode* QuadNode::getSuperiorRightChild() {
    return superiorRightChild;
}

QuadNode* QuadNode::getInferiorLeftChild() {
    return inferiorLeftChild;
}

QuadNode* QuadNode::getInferiorRightChild() {
    return inferiorRightChild;
}

void QuadNode::setSuperiorLeftChild(QuadNode* sleft) {
    superiorLeftChild = sleft;
}

void QuadNode::setSuperiorRightChild(QuadNode* sright) {
    superiorRightChild = sright;
}

void QuadNode::setInferiorLeftChild(QuadNode* ileft) {
    inferiorLeftChild = ileft;
}

void QuadNode::setInferiorRightChild(QuadNode* iright) {
    inferiorRightChild = iright;
}

bool QuadNode::isLeaf() {
    return (superiorLeftChild == nullptr && superiorRightChild == nullptr && inferiorLeftChild == nullptr && inferiorRightChild == nullptr);
}