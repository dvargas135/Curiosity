#pragma once

class Node;

class Edge {
public:
    Node* destination;
    double weight;
    Edge(Node* dest, double w);
};