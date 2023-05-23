#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <unordered_map>
#include <vector>
#include "Edge.hpp"
#include "Node.hpp"
#include "../classes/element.hpp"

class Graph {
    Node<Element>* getAdjListNode(Edge<Element>, double, Node<Element>*);
    int number_of_nodes;
    int edgeCount;
	
public:
    Node<Element>** head_node;
    // std::unordered_map<int, Airport*> airports;
    std::vector<Element> elements;

    // int calculate_edges(const std::vector<Element*>&, double);
    // int calculate_edges(double);
	
    // Graph(std::vector<Flight*>, std::unordered_map<int, Airport*>, const T&);
    Graph();
    Graph(std::vector<Element>, int);
    ~Graph();

    void print();
    double calcDistance(double, double, double, double);
    // std::vector<Airport*> dijkstra(const std::string&, const std::string&);
};

#endif