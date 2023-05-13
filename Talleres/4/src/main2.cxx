#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <limits>
#include <cmath>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <set>

class Airport {
public:
    std::string name;
    std::string code;
    double latitude;
    double longitude;

    Airport() = default;
    Airport(const std::string& name, const std::string& code, double latitude, double longitude) : name(name), code(code), latitude(latitude), longitude(longitude) {}

    bool operator==(const Airport& other) const {
        return code == other.code;
    }

    bool operator!=(const Airport& other) const {
        return code != other.code;
    }

    bool operator<(const Airport& other) const {
        return code < other.code;
    }
    ~Airport() {}
};

class Flight {
public:
    Airport* source;
    Airport* dest;
    double avg_time;
    double price;
};

template<typename T>
class Node {
public:
    T* data;
    double cost;
    Node<T>* next;
};

template<typename T>
class Edge {
public:
    T* data;
};

std::pair<Airport*, int> searchAirportByCode(const std::unordered_map<int, Airport*>& airports, const std::string& code) {
    int index = -1;
    Airport* airport = nullptr;

    for (const auto& p : airports) {
        if (p.second->code == code) {
            index = p.first;
            airport = p.second;
            break;
        }
    }
    return std::make_pair(airport, index);
}

class GraphAdjacencyListPrice {
	Node<Airport>* getAdjListNode(Edge<Flight> destination, Node<Airport>* head_node) {
		Node<Airport>* new_node = new Node<Airport>;

		new_node->cost = destination.data->price;
        new_node->data = destination.data->dest;
        new_node->next = head_node;

        return new_node;
	}
    int number_of_nodes;
	
public:
	Node<Airport>** head_node; // adjacency list as array of pointers to nodes
    std::unordered_map<int, Airport*> airports;
	
    GraphAdjacencyListPrice(std::vector<Flight*> flights, std::unordered_map<int, Airport*> airports) {
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

            int source_index = -1;
            auto ddd = searchAirportByCode(airports, src->code);
            source_index = ddd.second;

            Node<Airport>* new_node = getAdjListNode(destination, head_node[source_index]);
            head_node[source_index] = new_node;
        }
    }

    ~GraphAdjacencyListPrice() {
        for (int k = 0; k < number_of_nodes; k++) {
            delete head_node[k];
        }
        delete[] head_node;
    }

    void print() {
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

    std::vector<Airport*> cheapestPath(const std::string& source_airport_code, const std::string& destination_airport_code) {
        std::vector<Airport*> cheapest;

        auto source_result = searchAirportByCode(this->airports, source_airport_code);
        auto dest_result = searchAirportByCode(this->airports, destination_airport_code);

        if (source_result.second == -1 || dest_result.second == -1) {
            return cheapest;
        }

        int source_index = source_result.second;
        int dest_index = dest_result.second;

        const double INF = std::numeric_limits<double>::max();

        // dijkstra's
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
            return cheapest;
        }

        int current = dest_index;
        while (current != -1) {
            cheapest.insert(cheapest.begin(), airports[current]);
            current = previous[current];
        }
        return cheapest;
    }
};

std::unordered_map<int, Airport*> read_airports() {
    std::unordered_map<int, Airport*> airports;

    std::ifstream file("../aeropuertos.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open aeropuertos.csv" << std::endl;
        return airports;
    }

    std::string line;
    int index = 0;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string name, code;
        double latitude, longitude;
        if (!(std::getline(iss, name, ',') &&
                std::getline(iss, code, ',') &&
                (iss >> latitude) &&
                (iss.ignore() &&
                (iss >> longitude)))) {
            std::cerr << "Failed to parse line: " << line << std::endl;
            continue;
        }
        Airport* obj = new Airport(name, code, latitude, longitude);
        airports[index++] = obj;

        //delete airport object in the map reminder
    }
    return airports;
}

std::vector<Flight*> read_flights(std::unordered_map<int, Airport*>& airports) {
    std::vector<Flight*> flights;
    
    std::ifstream file("../vuelos.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open vuelos.csv" << std::endl;
        return flights;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string source_code, dest_code;
        double avg_time, price;
        if (!(std::getline(iss, source_code, ',') &&
                std::getline(iss, dest_code, ',') &&
                (iss >> avg_time) &&
                (iss.ignore() &&
                (iss >> price)))) {
            std::cerr << "Failed to parse line: " << line << std::endl;
            continue;
        }

        auto src = searchAirportByCode(airports, source_code);
        Airport* source = src.first;

        auto dst = searchAirportByCode(airports, dest_code);
        Airport* dest = dst.first;

        if (source == nullptr || dest == nullptr) {
            std::cerr << "Error: could not find source or destination airport for line \"" << line << "\"" << std::endl;
            continue;
        }

        Flight* new_flight = new Flight;
        new_flight->source = source;
        new_flight->dest = dest;
        new_flight->avg_time = avg_time;
        new_flight->price = price;
        flights.push_back(new_flight);

        // delete new_flight reminder
    }
    return flights;
}

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