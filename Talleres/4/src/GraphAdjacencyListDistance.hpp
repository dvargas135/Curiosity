#ifndef GRAPHADJACENCYLISTSHORTEST_HPP
#define GRAPHADJACENCYLISTSHORTEST_HPP

#include <unordered_map>
#include <vector>
#include "Edge.hpp"
#include "Flight.hpp"
#include "Node.hpp"

class GraphAdjacencyListDistance {
    Node<Airport>* getAdjListNode(Edge<Flight>, double, Node<Airport>*);
    int number_of_nodes;
	
public:
    Node<Airport>** head_node; // adjacency list as array of pointers to nodes
    std::unordered_map<int, Airport*> airports;
	
    GraphAdjacencyListDistance(std::vector<Flight*>, std::unordered_map<int, Airport*>);
    ~GraphAdjacencyListDistance();

    void print();
    double calcDistance(double, double, double, double);
    std::vector<Airport*> shortestPath(const std::string&, const std::string&);
};

#endif