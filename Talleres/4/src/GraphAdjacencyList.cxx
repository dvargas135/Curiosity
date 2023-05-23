#pragma once
#include "GraphAdjacencyList.hpp"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <type_traits>
#include <unordered_set>
#include <queue>
#include "Util.hpp"

template<typename T>
Node<Airport>* GraphAdjacencyList<T>::getAdjListNode(Edge<Flight> destination, double cost, Node<Airport>* head_node) {
    Node<Airport>* new_node = new Node<Airport>;

    new_node->cost = cost;
    new_node->data = destination.data->dest;
    new_node->next = head_node;

    return new_node;
}

template<typename T>
GraphAdjacencyList<T>::GraphAdjacencyList(std::vector<Flight*> flights, std::unordered_map<int, Airport*> airports, const T& type) {
    this->airports = airports;
    this->number_of_nodes = airports.size();
    int num_edges = flights.size();
    head_node = new Node<Airport>*[number_of_nodes]();

    for (int i = 0; i < number_of_nodes; i++) {
        head_node[i] = nullptr;
    }

    for (int k = 0; k < num_edges; k++) {
        Flight* flight = flights[k];

        Edge<Flight> destination;
        destination.data = flight;

        Airport* src = flight->source;
        Airport* dst = flight->dest;

        double weight = 0;

        if (type == "shortest") {
            weight = calcDistance(src->latitude, src->longitude, dst->latitude, dst->longitude);
        } else if (type == "fastest") {
            destination.data->avg_time;
        } else if (type == "cheapest") {
            weight = destination.data->price;
        }

        int source_index = -1;
        auto ddd = searchAirportByCode(airports, src->code);
        source_index = ddd.second;

        Node<Airport>* new_node = getAdjListNode(destination, weight, head_node[source_index]);
        head_node[source_index] = new_node;
    }
}

template<typename T>
GraphAdjacencyList<T>::~GraphAdjacencyList() {
    for (int k = 0; k < number_of_nodes; k++) {
        delete[] head_node[k];
    }
    delete[] head_node;
}

template<typename T>
void GraphAdjacencyList<T>::print() {
    for (int i = 0; i < number_of_nodes; i++) {
            if (head_node[i] == nullptr) {
            continue;
        }
        std::cout << "Airport " << i << " (" << head_node[i]->data->name << "): ";
        Node<Airport>* curr = head_node[i];
        while (curr) {
            std::cout << "(" << curr->data->code << ", " << curr->cost << ") ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }
}

template<typename T>
double GraphAdjacencyList<T>::calcDistance(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

template<typename T>
std::vector<Airport*> GraphAdjacencyList<T>::dijkstra(const std::string& source_airport_code, const std::string& destination_airport_code) {
    std::vector<Airport*> shortest;

    auto source_result = searchAirportByCode(this->airports, source_airport_code);
    auto dest_result = searchAirportByCode(this->airports, destination_airport_code);

    if (source_result.second == -1 || dest_result.second == -1) {
        return shortest;
    }

    int source_index = source_result.second;
    int dest_index = dest_result.second;
    const double INF = std::numeric_limits<double>::max();

    // dijkstra's for shortest route
    std::vector<double> cost(number_of_nodes, INF);
    std::vector<bool> visited(number_of_nodes, false);
    std::vector<int> previous(number_of_nodes, -1);
    cost[source_index] = 0;

    std::priority_queue<std::pair<double, int>, std::vector<std::pair<double, int>>, std::greater<std::pair<double, int>>> pq;
    pq.push(std::make_pair(0, source_index));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) {
            continue;
        }
        visited[u] = true;

        Node<Airport>* head_node = this->head_node[u];

        while (head_node != nullptr) {
            int v = searchAirportByCode(airports, head_node->data->code).second;

            double new_cost = cost[u] + head_node->cost;

            if (new_cost < cost[v]) {
                cost[v] = new_cost;
                previous[v] = u;
                pq.push(std::make_pair(cost[v], v));
            }
            if (v == dest_index) {
                break;
            }
            head_node = head_node->next;
        }
    }

    if (previous[dest_index] == -1) {
        return shortest;
    }

    int current = dest_index;
    
    while (current != -1) {
        shortest.insert(shortest.begin(), airports[current]);
        current = previous[current];
    }

    return shortest;
}