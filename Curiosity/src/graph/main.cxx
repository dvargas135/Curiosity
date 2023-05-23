#include <iostream>
#include <vector>
#include <cmath>

struct Coordinate {
    double x;
    double y;
};

double calculateDistance(const Coordinate& c1, const Coordinate& c2) {
    double dx = c2.x - c1.x;
    double dy = c2.y - c1.y;
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    std::vector<Coordinate> coordinates = {
        {3.5, 1.2},
        {38.2, 2.0},
        {50.23, 98.66},
        {1.98, 49.3},
        {15.32, 6.45}
    };

    // Threshold distance to form an edge
    double threshold = 20.0;

    std::vector<std::pair<int, int>> edges;

    // Calculate edges based on distance
    for (size_t i = 0; i < coordinates.size(); ++i) {
        for (size_t j = i + 1; j < coordinates.size(); ++j) {
            double distance = calculateDistance(coordinates[i], coordinates[j]);
            if (distance <= threshold) {
                edges.emplace_back(i, j);
            }
        }
    }

    // Print nodes
    std::cout << "Nodes:\n";
    for (size_t i = 0; i < coordinates.size(); ++i) {
        std::cout << "(" << coordinates[i].x << ", " << coordinates[i].y << ")\n";
    }

    // Print edges
    std::cout << "Edges:\n";
    for (const auto& edge : edges) {
        std::cout << edge.first << " -- " << edge.second << "\n";
    }

    return 0;
}