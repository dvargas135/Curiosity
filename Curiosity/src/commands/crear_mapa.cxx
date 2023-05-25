#include "crear_mapa.hpp"
#include "../graph/Graph.hpp"
#include "../util/util.hpp"

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <functional>
#include <unordered_set>
#include <stack>

void crear_mapa(std::string cc_str, System& sys) {
    if (sys.getElements().empty()) {
        std::cout << "La informacion requerida no esta almacenada en memoria." << std::endl;
        return;
    }

    if (!is_positive(cc_str)) {
        printf("El coeficiente de conectividad no es un número natural.\n");
        return;
    }

    double cc = std::stod(cc_str);
    std::vector<Element> ets = sys.getElements();
    
    Graph* graph = new Graph(sys.getElements(), cc);
    sys.setGraph(graph);
    printf("Mapa creado exitosamente. Escriba `ver_mapa` para imprimirlo.\n");
}

void ver_mapa(System& sys) {
    Graph* g = sys.getGraph();
    g->print();
}