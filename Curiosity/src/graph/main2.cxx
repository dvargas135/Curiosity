#include <iostream>
#include <vector>

class Vector {
public:
    double x;
    double y;

    Vector(double xVal, double yVal) : x(xVal), y(yVal) {}
};

class Element {
public:
    std::string type;
    double size;
    std::string measurement_unit;
    Vector position;
};

template <typename T>
class Node {
public:
    T element;
    std::vector<Node<T>*> adjacentNodes;

    Node(const T& elem) : element(elem) {}
};

class Edge {
public:
    Node<Element>* source;
    Node<Element>* destination;
    int weight;

    Edge(Node<Element>* src, Node<Element>* dest, int w) : source(src), destination(dest), weight(w) {}
};

class Graph {
public:
    std::vector<Node<Element>*> nodes;

    void addEdge(Node<Element>* source, Node<Element>* destination, int weight) {
        Edge* edge = new Edge(source, destination, weight);
        source->adjacentNodes.push_back(destination);
        nodes.push_back(source);
    }

    void printGraph() {
        for (Node<Element>* node : nodes) {
            std::cout << "Node " << node->element.type << " is connected to: ";
            for (Node<Element>* adjacent : node->adjacentNodes) {
                std::cout << adjacent->element.type << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph graph;

    Node<Element>* nodeA = new Node<Element>(Element{"TypeA", 5.0, "cm", Vector{1.0, 2.0}});
    Node<Element>* nodeB = new Node<Element>(Element{"TypeB", 3.0, "m", Vector{3.0, 4.0}});
    Node<Element>* nodeC = new Node<Element>(Element{"TypeC", 7.0, "in", Vector{5.0, 6.0}});

    graph.addEdge(nodeA, nodeB, 2);
    graph.addEdge(nodeB, nodeC, 6);
    graph.addEdge(nodeA, nodeC, 9);

    graph.printGraph();

    // Cleanup
    delete nodeA;
    delete nodeB;
    delete nodeC;

    return 0;
}
