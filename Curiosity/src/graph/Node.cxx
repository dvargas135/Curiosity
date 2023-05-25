#include "Node.hpp"
#include "Edge.hpp"

Node::Node(const Element& elem) : element(elem) {}

void Node::addNeighbor(Node* neighbor, double weight) {
    neighbors.push_back(Edge(neighbor, weight));
}