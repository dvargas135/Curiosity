#pragma once

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "../classes/element.hpp"
#include "../classes/vector.hpp"
#include "Node.hpp"

class Graph {
public:
    std::vector<Node*> nodes;
    std::unordered_map<std::string, std::vector<Node*>> typeNodeMap;
    bool isInitialized = false;
    
    Graph();
    Graph(std::vector<Element>, double);
    ~Graph();
    
    Node* addNode(const Element& element);
    std::vector<Node*> getNodesByType(const std::string& type) const;
    double calculateDistance(const Vector&, const Vector&);
    void print();
    bool isEmpty() const;
};