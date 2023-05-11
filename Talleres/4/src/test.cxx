#include <iostream>
using namespace std;

// Syntax to create node
struct Node {
    int value,cost;
    Node* next;
};

// This will store the graph edge details (source and destination)
struct graphEdge {
    int source, destination,edgeweight;
};

class GraphAdjacencyList {
    // Create a new node for the adjacency list
    Node* getNeighbourVertex(int destination,int edgeweight, Node* head_node)    {
        Node* new_node = new Node;
        new_node->value = destination;
        new_node->cost = edgeweight;

        new_node->next = head_node;

        return new_node;
    }

    // It will store the total number of nodes in a graph
    int number_of_nodes;

public:
    Node **head_node;

    GraphAdjacencyList(graphEdge graphEdges[], int num, int number_of_nodes) {
        // dynamic memory allocation
        head_node = new Node*[number_of_nodes]();
        this->number_of_nodes = number_of_nodes;

        // initialize headnode for every edge of graph
        for (int k = 0; k < number_of_nodes; k++) {
            head_node[k] = nullptr;
        }

        for (int k = 0; k < num; k++)         {
            int source = graphEdges[k].source;
            int destination = graphEdges[k].destination;
            int edgeweight = graphEdges[k].edgeweight;

            Node* new_node = getNeighbourVertex(destination, edgeweight,
                  head_node[source]);
            head_node[source] = new_node;
        }
    }

    GraphAdjacencyList() {
        for (int k = 0; k < number_of_nodes; k++) {
            delete[] head_node[k];
        }

        delete[] head_node;
    }
};

void display(Node* displayptr, int k) {
    while (displayptr != nullptr){
      cout << "(" << k << ", " <<
      displayptr->value << ", " << displayptr->cost << ") ";
        displayptr = displayptr->next;
    }
    cout << endl;
}

int main() {
    graphEdge graphEdges[] = {
      // (x,y,z)=> these are x and y values which represent an edge    
      // from x to y with weight w
        {0, 1, 4}, {1, 2, 6}, {2, 0, 3}, {2, 1, 5}, {3, 4, 8},
        {4, 1, 1}, {3, 2, 7}
    };

    // total number of nodes from 0 to 5, so total nodes is 6
    int number_of_nodes = 6;

    // this method will calculate the number of edges in the graph
    int num_edges = sizeof(graphEdges)/sizeof(graphEdges[0]);

    // create the graph
    GraphAdjacencyList graph(graphEdges, num_edges, number_of_nodes);

    // display the adjacency list of the graph
    for (int k = 0; k < number_of_nodes; k++){
        cout << k;

        display(graph.head_node[k],k);
    }

    return 0;
}