#include "Graph.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <type_traits>
#include <unordered_set>
#include <queue>
#include "../util/util.hpp"

Node<Element>* Graph::getAdjListNode(Edge<Element> destination, double cost, Node<Element>* head_node) {
    Node<Element>* new_node = new Node<Element>;
	
    new_node->cost = cost;
    new_node->data = destination.data;
    new_node->next = head_node;
	
    return new_node;
}

Graph::Graph() {}

Graph::Graph(std::vector<Element> elements, int threshold) {
    head_node = new Node<Element>*[elements.size()]();
    this->number_of_nodes = elements.size();
    this->elements = elements;

    for (int i = 0; i < number_of_nodes; i++) {
        head_node[i] = nullptr;
    }

    int edCount = 0;
    int num_nodes = elements.size();

    for (int i = 0; i < num_nodes; ++i) {
        Element node1 = elements[i]; // source

        for (int j = i + 1; j < num_nodes; ++j) {
            Element node2 = elements[j]; // destination
            
            double distance = std::sqrt(std::pow(node2.getPosition().getX() - node1.getPosition().getX(), 2) + std::pow(node2.getPosition().getY() - node1.getPosition().getY(), 2));

            if (distance <= threshold) {
                std::cout << node1.getPosition().getPos() << " - " << node2.getPosition().getPos() << ", " << distance << std::endl;

                Edge<Element> destination;
                destination.data = node2;

                Node<Element> *new_node = getAdjListNode(destination, distance, head_node[i]);
                head_node[i] = new_node;
				
                edCount++;
            }
        }
    }
    this->edgeCount = edCount;
}

Graph::~Graph() {
    for (int k = 0; k < number_of_nodes; k++) {
        head_node[k] = nullptr;
    }
    delete[] head_node;
}

void Graph::print() {
    for (int i = 0; i < number_of_nodes; i++) {
        if (head_node[i] == nullptr) {
            continue;
        }

        Node<Element>* curr = head_node[i];
        std::cout << i << ". " << curr->data.getPosition().getPos() << " ";

        while (curr) {
            std::cout << "-> (" << curr->data.getPosition().getPos() << ", " << curr->cost << ")";
            curr = curr->next;
        }
        
        std::cout << std::endl;
    }
}
