#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <cstdio>
#include <stdexcept>
#include <string>
#include <algorithm>
#include <ctype.h>
#include <stdio.h>

class Vector {
    public:
        Vector() : x(0), y(0) {}
        Vector(double x, double y) : x(x), y(y) {}
        double x;
        double y;
};

class Element {
    public:
        Element() {}
        Element(const std::string& t, double s, std::string& mu, const Vector& p) : type(t), size(s), measurement_unit(mu), position(p) {}
        std::string type;
        double size;
        std::string measurement_unit;
        Vector position;
};

// class Node {
// public:
//     double x;
//     double y;
//     Node(double x_val, double y_val) : x(x_val), y(y_val) {}
// };

template<typename T>
class Node {
public:
    T* data;
    double cost;
    Node<T>* next;

    Node(T* data, double cost) : data(data), cost(cost), next(nullptr) {}
    Node() {}
    ~Node() {}
};

template<typename T>
class Edge {
public:
    Node<T>* data;
    Edge() {}
    Edge(Node<T>* data) : data(data) {}
};

std::vector<std::pair<Node<Element>*, Node<Element>*>> calculate_edges(const std::vector<Node<Element>*>& coordinates, double threshold) {
    std::vector<std::pair<Node<Element>*, Node<Element>*>> edges;
    int num_nodes = coordinates.size();

    for (int i = 0; i < num_nodes; ++i) {
        Node* node1 = coordinates[i];

        for (int j = i + 1; j < num_nodes; ++j) {
            Node* node2 = coordinates[j];
            double distance = std::sqrt(std::pow(node2->x - node1->x, 2) + std::pow(node2->y - node1->y, 2));

            if (distance <= threshold) {
                edges.push_back(std::make_pair(node1, node2));
            }
        }
    }

    return edges;
}

int main() {
    std::vector<Element*> eee = cargar_elementos();
    
    // std::vector<Node*> coordinates = {
    //     new Node(3.5, 1.2),
    //     new Node(38.2, 2.0),
    //     new Node(50.23, 98.66),
    //     new Node(1.98, 49.3),
    //     new Node(15.32, 6.45)
    // };

    double threshold = 50.0;
    std::vector<std::pair<Node<Element*>*, Node<Element*>*>> edges = calculate_edges(eee, threshold);

    for (const auto& edge : edges) {
        std::cout << "(" << edge.first->x << ", " << edge.first->y << ") -- "
                  << "(" << edge.second->x << ", " << edge.second->y << ")\n";
    }
    
    // Clean up dynamically allocated nodes
    for (Element* node : eee) {
        delete node;
    }

    return 0;
}