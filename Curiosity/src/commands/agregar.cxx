#include "agregar.hpp"
#include "../util/util.hpp"
#include "../classes/command.hpp"
#include "../classes/element.hpp"

#include <string>
#include <cstdio>
#include <stdexcept>

void agregar_movimiento(std::string type, std::string magnitude, std::string measurement_unit, System& sys) {
    double mag;

    try {
        mag = std::stod(magnitude);
    } catch (const std::invalid_argument& e) {
        printf("La información del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad).\n");
        return;
    }

    if ((type == "avanzar") && mag >= 0.0 && (measurement_unit == "cm" || measurement_unit == "m")) {
        Movement* m = new Movement(type, mag, measurement_unit);
        sys.addCommand(m);
        delete m;
    } else if ((type == "girar") && measurement_unit == "g") {
        Movement* m = new Movement(type, mag, measurement_unit);
        sys.addCommand(m);
        delete m;
    } else {
        printf("La información del movimiento no corresponde a los datos esperados (tipo, magnitud, unidad).\n");
        return;
    }
    printf("El comando de movimiento ha sido agregado exitosamente.\n");
}

void agregar_analisis(std::string type, std::string obj, std::string comment, System& sys) {
    if (!(type == "fotografiar" || type == "composicion" || type == "perforar") || (!comment.empty() && !(comment.front() == '\'' && comment.back() == '\''))) {
        printf("La información del análisis no corresponde a los datos esperados (tipo, objeto, comentario).\n");
    }
    if (comment.empty()) { comment = ""; }
    Analysis* a = new Analysis(type, obj, comment);
    sys.addCommand(a);
    delete a;
    
    printf("El comando de análisis ha sido agregado exitosamente.\n");
}

void agregar_elemento(std::string type, std::string size_str, std::string measurement_unit, std::string x_str, std::string y_str, System& sys) {
    std::string errorMsg = "La información del análisis no corresponde a los datos esperados (tipo, objeto, comentario).";

    double size, x, y;

    try {
        size = std::stod(size_str);
        x = std::stod(x_str);
        y = std::stod(y_str);
    } catch (const std::invalid_argument& e) {
        printf("%s \n", errorMsg.c_str());
        return;
    }

    if (!(type == "roca" || type == "crater" || type == "monticulo" || type == "duna") && !(size >= 0.0) && (measurement_unit == "cm" || measurement_unit == "m")) {
        printf("%s\n", errorMsg.c_str());
        return;
    }
    Element* e = new Element(type, size, measurement_unit, x, y);
    sys.addElement(e);
    delete e;

    printf("El elemento ha sido agregado exitosamente.\n");
}