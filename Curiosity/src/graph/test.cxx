#include <iostream>
#include <vector>
#include <cmath>

class Node {
public:
    double x;
    double y;

    Node(double x_val, double y_val) : x(x_val), y(y_val) {}
};

std::vector<std::pair<Node*, Node*>> calculate_edges(const std::vector<Node*>& coordinates, double threshold) {
    std::vector<std::pair<Node*, Node*>> edges;
    int num_nodes = coordinates.size();

    for (int i = 0; i < num_nodes; ++i) {
        Node* node1 = coordinates[i];

        for (int j = i + 1; j < num_nodes; ++j) {
            Node* node2 = coordinates[j];
            double distance = std::sqrt(std::pow(node2->x - node1->x, 2) + std::pow(node2->y - node1->y, 2));
            std::cout<<distance<<std::endl;
            if (distance <= threshold) {
                edges.push_back(std::make_pair(node1, node2));
            }
        }
    }
    std::cout<<"ddd"<<std::endl;

    return edges;
}

int main() {
    std::vector<Node*> coordinates = {
        new Node(3.5, 1.2),
        new Node(38.2, 2.0),
        new Node(50.23, 98.66),
        new Node(1.98, 49.3),
        new Node(15.32, 6.45)
    };

    double threshold = 50.0;
    std::vector<std::pair<Node*, Node*>> edges = calculate_edges(coordinates, threshold);

    for (const auto& edge : edges) {
        std::cout << "(" << edge.first->x << ", " << edge.first->y << ") -- "
                  << "(" << edge.second->x << ", " << edge.second->y << ")\n";
    }

    // Clean up dynamically allocated nodes
    for (Node* node : coordinates) {
        delete node;
    }

    return 0;
}