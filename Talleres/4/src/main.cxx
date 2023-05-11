#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <cmath>

class Airport {
public:
    std::string city;
    std::string airport_code;
    double latitude;
    double longitude;
};

class Flight {
public:
    std::string airport_i;
    std::string airport_j;
    int avg_time;
    int price;
    int num_flights;
};

template<typename T>
class Node {
public:
    T* data;
    std::string cost;
    Node<T>* next;
};

template<typename T>
class Edge {
public:
    T* data;
    std::string source;
    std::string dest;
};

class GraphAdjacencyList {
private:
    int num_vertices;
    Node<Airport>** adjacency_list; // array of pointers to nodes
public:
    GraphAdjacencyList(int num_v) {
        num_vertices = num_v;
        adjacency_list = new Node<Airport>*[num_v];
        for (int i = 0; i < num_v; i++) {
            adjacency_list[i] = nullptr;
        }
    }
    
    ~GraphAdjacencyList() {
        for (int i = 0; i < num_vertices; i++) {
            Node<Airport>* current = adjacency_list[i];
            while (current != nullptr) {
                Node<Airport>* next = current->next;
                delete current->data;
                delete current;
                current = next;
            }
        }
        delete[] adjacency_list;
    }

    int hash_function(const std::string& s) const {
        int hash = 0;
        for (char c : s) {
            hash += c;
        }
        return hash % capacity;
    }
    
    void add_vertex(std::string value, Airport* data) {
        Node<Airport>* new_vertex = new Node<Airport>();
        new_vertex->value = value;
        new_vertex->data = data;
        new_vertex->next = nullptr;
        
        int index = hash_function(value);
        if (adjacency_list[index] == nullptr) {
            adjacency_list[index] = new_vertex;
        } else {
            Node<Airport>* current = adjacency_list[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = new_vertex;
        }
    }

    void add_edge(std::string source, std::string dest, Flight* data) {
        Node<Airport>* source_node = get_vertex_node(source);
        Node<Airport>* dest_node = get_vertex_node(dest);
        
        if (source_node == nullptr || dest_node == nullptr) {
            return;
        }
        
        Edge<Flight>* new_edge = new Edge<Flight>();
        new_edge->source = source;
        new_edge->dest = dest;
        new_edge->data = data;
        
        Node<Airport>* current = adjacency_list[hash_function(source)];
        while (current != nullptr) {
            if (current->data->airport_code == source) {
                break;
            }
            current = current->next;
        }
        
        if (current == nullptr) {
            return;
        }
        
        if (current->data->outgoing_edges == nullptr) {
            current->data->outgoing_edges = new_edge;
        } else {
            Edge<Flight>* outgoing_edge = current->data->outgoing_edges;
            while (outgoing_edge->next != nullptr) {
                outgoing_edge = outgoing_edge->next;
            }
            outgoing_edge->next = new_edge;
        }
    }
    
    Node<Airport>* get_vertex_node(std::string airport_code) const {
        Node<Airport>* current = adjacency_list[hash_function(airport_code)];
        while (current != nullptr) {
            if (current->data->airport_code == airport_code) {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }
    
    Edge<Flight>* get_edge_node(std::string source, std::string dest) const {
        Node<Airport>* source_node = get_vertex_node(source);
        if (source_node == nullptr) {
            // source vertex not found
            return nullptr;
        }
        Edge<Flight>* outgoing_edge = source_node->data->outgoing_edges;
        while (outgoing_edge != nullptr) {
            if (outgoing_edge->dest == dest) {
                return outgoing_edge;
            }
            outgoing_edge = outgoing_edge->next;
        }
        // edge not found
        return nullptr;
    }
};


int main() {
    return 0;
}