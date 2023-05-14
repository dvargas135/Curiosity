#pragma once

#include <unordered_map>
#include <vector>
#include "Edge.hpp"
#include "Flight.hpp"
#include "Node.hpp"

template<typename T>
class GraphAdjacencyList {
    Node<Airport>* getAdjListNode(Edge<Flight>, double, Node<Airport>*);
    int number_of_nodes;
	
public:
    Node<Airport>** head_node; // adjacency list as array of pointers to nodes
    std::unordered_map<int, Airport*> airports;
	
    GraphAdjacencyList(std::vector<Flight*>, std::unordered_map<int, Airport*>, const T&);
    ~GraphAdjacencyList();

    void print();
    double calcDistance(double, double, double, double);
    std::vector<Airport*> dijkstra(const std::string&, const std::string&);
};

#include "GraphAdjacencyList.cxx"