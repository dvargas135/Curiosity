#include "crear_mapa.hpp"
#include "../graph/Graph.hpp"
#include <cstdio>

void crear_mapa(std::string threshold_str, System& sys) {
    int threshold = std::stod(threshold_str);
    Graph graph(sys.getElements(), threshold);
    std::cout<<"ddd"<<std::endl;
    graph.print();

    // sys.clearElements();
    
    // graph.calculate_edges(threshold);
}