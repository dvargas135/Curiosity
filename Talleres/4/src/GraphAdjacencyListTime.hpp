#ifndef GRAPHADJACENCYLISTTIME_HPP
#define GRAPHADJACENCYLISTTIME_HPP

#include <unordered_map>
#include <vector>
#include "Edge.hpp"
#include "Flight.hpp"
#include "Node.hpp"

class GraphAdjacencyListTime {
    Node<Airport>* getAdjListNode(Edge<Flight>, Node<Airport>*);
    int number_of_nodes;
	
public:
    Node<Airport>** head_node; // adjacency list as array of pointers to nodes
    std::unordered_map<int, Airport*> airports;
	
    GraphAdjacencyListTime(std::vector<Flight*>, std::unordered_map<int, Airport*>);
    ~GraphAdjacencyListTime();

    void print();
    std::vector<Airport*> fastestPath(const std::string&, const std::string&);
};

#endif