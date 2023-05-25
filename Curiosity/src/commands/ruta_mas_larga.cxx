#include "ruta_mas_larga.hpp"
#include "../graph/Graph.hpp"

#include <sstream>
#include <vector>

void ruta_mas_larga(System& sys) {
    Graph* graph = sys.getGraph();
    
    if (graph->isEmpty()) {
        std::cout << "El mapa no ha sido generado todavía (con el comando crear_mapa)." << std::endl;
        return;
    }

    std::pair<double, std::string> maxDistancePath = findPathWithMaxDistance(graph);
    double maxDistance = maxDistancePath.first;
    std::string path = maxDistancePath.second;

    std::istringstream iss(path);
    std::vector<std::string> lines;
    std::string line;

    while (std::getline(iss, line, '\n')) {
        lines.push_back(line);
    }

    std::cout << "Los puntos de interes mas alejados entre si son " << lines[1].substr(3) << " y " << lines[lines.size()-1].substr(3) << ".\nLa ruta que los conecta tiene una longitud total de " << maxDistance << " y pasa por los siguentes elementos:" << path << std::endl;
}

void findMaxDistancePath(const Node* node, const std::string& currentPath, double currentDistance, std::unordered_set<const Node*>& visited, double& maxDistance, std::string& maxPath) {
    visited.insert(node);

    if (currentDistance > maxDistance) {
        maxDistance = currentDistance;
        maxPath = currentPath;
    }

    for (const Edge& edge : node->neighbors) {
        Node* neighbor = edge.destination;
        if (visited.find(neighbor) == visited.end()) {
            std::string str = std::to_string(neighbor->element.getSize());
            str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
            str.erase ( str.find_last_not_of('.') + 1, std::string::npos );

            std::string newPath = currentPath + "\n - [" + neighbor->element.getType() + ", " + str + neighbor->element.getMeasurementUnit() + ", " + neighbor->element.getPosition().getPos() + "]";
            double newDistance = currentDistance + edge.weight;
            findMaxDistancePath(neighbor, newPath, newDistance, visited, maxDistance, maxPath);
        }
    }
    visited.erase(node);
}

std::pair<double, std::string> findPathWithMaxDistance(const Graph* graph) {
    double maxDistance = 0.0;
    std::string maxPath;
    std::unordered_set<const Node*> visited;

    for (const Node* node : graph->nodes) {
        std::string str = std::to_string(node->element.getSize());
        str.erase ( str.find_last_not_of('0') + 1, std::string::npos );
        str.erase ( str.find_last_not_of('.') + 1, std::string::npos );

        std::string startNode = "\n - [" + node->element.getType() + ", " + str + node->element.getMeasurementUnit() + ", " + node->element.getPosition().getPos() + "]";
        findMaxDistancePath(node, startNode, 0.0, visited, maxDistance, maxPath);
    }
    
    return std::make_pair(maxDistance, maxPath);
}