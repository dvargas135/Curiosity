#include <iostream>
#include "GraphAdjacencyListPrice.hpp"
#include "Util.hpp"

int main() {
    std::unordered_map<int, Airport*> airports = read_airports();
    std::vector<Flight*> flights = read_flights(airports);

    GraphAdjacencyListPrice graph(flights, airports);
    // graph.print();
    std::vector<Airport*> cheapest = graph.cheapestPath("ACY", "SFO");

    for (int i = 0; i < cheapest.size(); i++) {
        std::cout << cheapest[i]->code;
        if (i != cheapest.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << std::endl;

    for (auto flight : flights) {
        delete flight;
    }
    for (const auto& it : airports) {
        delete it.second;
    }

    return 0;
}