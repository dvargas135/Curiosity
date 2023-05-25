#include "Graph.hpp"
#include "Edge.hpp"

#include <functional>
#include <iostream>
#include <algorithm>
#include <cmath>

Graph::Graph() {}

Graph::Graph(std::vector<Element> elements, double connectivityCoefficient) {
    isInitialized = true;
    std::vector<Node*> nodePointers;
    
    for (Element& element : elements) {
        Node* node = addNode(element);
        nodePointers.push_back(node);
    }
    
    std::size_t numNeighbors = static_cast<std::size_t>(elements.size() * connectivityCoefficient);
    
    for (Node* currentNode : nodePointers) {
        std::vector<std::pair<double, Node*>> distances;
        
        for (Node* otherNode : nodePointers) {
            if (currentNode == otherNode) continue;
            double distance = calculateDistance(currentNode->element.getPosition(), otherNode->element.getPosition());
            distances.emplace_back(distance, otherNode);
        }
        
        std::sort(distances.begin(), distances.end());
        
        for (std::size_t i = 0; i < numNeighbors && i < distances.size(); ++i) {
            double distance = distances[i].first;
            Node* neighborNode = distances[i].second;
            currentNode->addNeighbor(neighborNode, distance);
        }
    }
}

Graph::~Graph() {
    if (!nodes.empty()) {
        for (Node* node : nodes) {
            if (node != nullptr) {
                delete node;
            }
        }
    }
}

Node* Graph::addNode(const Element& element) {
    Node* newNode = new Node(element);
    nodes.push_back(newNode);
    typeNodeMap[element.getType()].push_back(newNode);
    return newNode;
}

std::vector<Node*> Graph::getNodesByType(const std::string& type) const {
    auto it = typeNodeMap.find(type);
    return (it != typeNodeMap.end()) ? it->second : std::vector<Node*>();
}

double Graph::calculateDistance(const Vector& v1, const Vector& v2) {
    double dx = v1.getX() - v2.getX();
    double dy = v1.getY() - v2.getY();
    return std::sqrt(dx * dx + dy * dy);
}

void Graph::print() {
    for (Node* node : nodes) {
        std::cout << "Elemento: [" << node->element.getType() << ", " << node->element.getSize() << node->element.getMeasurementUnit() << ", (" << node->element.getPosition().getX() << ", " << node->element.getPosition().getY() << ")]" << std::endl;
        
        std::cout << "Vecinos: " << std::endl;
        for (const Edge& edge : node->neighbors) {
            std::cout << "- [" << edge.destination->element.getType() << ", " << edge.destination->element.getSize() << edge.destination->element.getMeasurementUnit() << ", (" << edge.destination->element.getPosition().getX() << ", " << edge.destination->element.getPosition().getY() << ")]. ";
            std::cout << "Distancia: " << edge.weight << std::endl;
        }
        
        std::cout << std::endl;
    }
}

bool Graph::isEmpty() const {
    return !isInitialized;
}