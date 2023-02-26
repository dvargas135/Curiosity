#include "agregar.h"
#include "../../util/util.h"

#include <iostream>
#include <string>

void agregar_movimiento(std::string type, std::string magnitude, std::string measurement_unit, Cmds& c) {
    if (type == "avanzar") {
        if (is_positive(magnitude)) {
            if (measurement_unit == "cm" || measurement_unit == "m") {
                c.addCommand({type, magnitude, measurement_unit});
                std::cout << " El comando de movimiento ha sido agregado exitosamente." << std::endl;
            } else {
                std::cout << " magnitud inválida!" << std::endl;
                return;
            }
        } else {
            std::cout << " medida inválida!" << std::endl;
            return;
        }
    } else if (type == "girar") {
        if (is_number(magnitude)) {
            if (measurement_unit == "g") {
                c.addCommand({type, magnitude, measurement_unit});
                std::cout << " El comando de movimiento ha sido agregado exitosamente." << std::endl;
            } else {
                std::cout << " magnitud inválida!" << std::endl;
                return;
            }
        } else {
            std::cout << " medida inválida!" << std::endl;
            return;
        }
    } else {
        std::cout << " tipo de movimiento inválido!" << std::endl;
        return;
    }
}

void agregar_analisis(std::string type, std::string obj, std::string comment, Cmds& c) {
    if (type == "fotografiar" || type == "composicion" || type == "perforar") {
        if (obj == "roca" || obj == "crater" || obj == "monticulo" || obj == "duna") {
            if (!comment.empty() && (comment.front() == '\'' && comment.back() == '\'')) {
                c.addCommand({type, obj, comment});
                std::cout << " El comando de análisis ha sido agregado exitosamente." << std::endl;
            } else {
                std::cout << " el comentario debe estar encerrado entre comillas simples!" << std::endl;
                return;
            }
            c.addCommand({type, obj});
            std::cout << " El comando de análisis ha sido agregado exitosamente." << std::endl;
        } else {
            std::cout << " tipo de análisis inválido!" << std::endl;
            return;
        }
    } else {
        std::cout << " objeto inválido!" << std::endl;
        return;
    }
}

void agregar_elemento(std::string type, std::string size, std::string measurement_unit, std::string x, std::string y, Elmts& e) {
    if (type == "fotografiar" || type == "composicion" || type == "perforar") {
        if (is_positive(size)) {
            if (measurement_unit == "cm" || measurement_unit == "m") {
                if (is_number(x) && is_number(y)) {
                    e.addElement({type, size, measurement_unit, x, y});
                    std::cout << " El elemento ha sido agregado exitosamente." << std::endl;
                } else {
                    std::cout << " valores incorrectos para x o y!" << std::endl;
                    return;
                }
            } else {
                std::cout << " magnitud inválida!" << std::endl;
                return;
            }
        } else {
            std::cout << " tamaño inválido!" << std::endl;
            return;
        }
    } else {
        std::cout << " tipo de componente inválido!" << std::endl;
        return;
    }
}