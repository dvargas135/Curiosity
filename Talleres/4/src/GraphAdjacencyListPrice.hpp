#ifndef GRAPHADJACENCYLISTPRICE_HPP
#define GRAPHADJACENCYLISTPRICE_HPP

#include <unordered_map>
#include <vector>
#include "Edge.hpp"
#include "Flight.hpp"
#include "Node.hpp"

class GraphAdjacencyListPrice {
    Node<Airport>* getAdjListNode(Edge<Flight>, Node<Airport>*);
    int number_of_nodes;
	
public:
    Node<Airport>** head_node; // adjacency list as array of pointers to nodes
    std::unordered_map<int, Airport*> airports;
	
    GraphAdjacencyListPrice(std::vector<Flight*>, std::unordered_map<int, Airport*>);
    ~GraphAdjacencyListPrice();

    void print();
    std::vector<Airport*> cheapestPath(const std::string&, const std::string&);
};

#endif