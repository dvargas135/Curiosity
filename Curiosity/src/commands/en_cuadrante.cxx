#include "en_cuadrante.hpp"
#include "../util/util.hpp"
#include "../classes/vector.hpp"
#include "../trees/quad/point.hpp"

#include <cstdio>
#include <queue>

// std::vector<Point> en_cuadrante(std::string x1_str, std::string x2_str, std::string y1_str, std::string y2_str, System& s) {
void en_cuadrante(std::string x1_str, std::string x2_str, std::string y1_str, std::string y2_str, System& s) {
    if (!(is_number(x1_str) && is_number(x2_str) && is_number(y1_str) && is_number(y2_str))) {
        printf("La información del cuadrante no corresponde a los datos esperados (x_min, x_max, y_min, y_max)\n");
        return;
    }

    std::string errorMsg = "Los puntos no han sido ubicados todavía (con el comando ubicar_elementos).";
    if (s.getTree().isEmpty()) {
        printf("%s\n", errorMsg.c_str());
        return;
    }

    double x1, x2, y1, y2;
    x1 = std::stod(x1_str);
    x2 = std::stod(x2_str);
    y1 = std::stod(y1_str);
    y2 = std::stod(y2_str);
    std::vector<Point> puntos;

    puntos = s.getTree().listaPreorder(s.getTree().getRoot(), x1, x2, y1, y2, puntos);

    printf("Los elementos ubicados en el cuadrante solicitado son:\n");

    comparePoints(s.getElements(), puntos, s);
    
    // for (auto a : puntos) {
    //     printf(" %f, %f\n", a.getX(), a.getY());
    // }

    // return puntos;
}

void comparePoints(std::vector<Element> elements_vec, const std::vector<Point>& points, System& s) {
    std::queue<Element> elements;

    for (const auto& element : elements_vec) {
        elements.push(element);
    }
    
    while (!elements.empty()) {
        Element e = elements.front();
        elements.pop();
        for (Point p : points) {
            if (p.x == e.getPosition().getX() && p.y == e.getPosition().getY()) {
                std::cout << "---" << std::endl;
                std::cout << "Type: " << e.getType() << std::endl;
                std::cout << "Size: " << e.getSize() << " " << e.getMeasurementUnit() << std::endl;
                std::cout << "Position: (" << e.getPosition().getX() << ", " << e.getPosition().getY() << ")" << std::endl;
            }
        }
    }
}