#pragma once

#include <vector>

#include "../classes/element.hpp"
#include "Edge.hpp"

class Node {
public:
    Element element;
    std::vector<Edge> neighbors;
    
    Node(const Element& elem);
    void addNeighbor(Node* neighbor, double weight);
};