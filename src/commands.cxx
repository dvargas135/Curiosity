#include "commands.h"
#include "util.h"

#include <iostream>
#include <vector>
#include <string>
#include <map>

void cargar_comandos(std::string fileName) {
    
}

void cargar_elementos(std::string fileName) {

}

void agregar_movimiento(std::string type, std::string magnitude, std::string measure) {
    if (type == "avanzar") {
        if (magnitude == "cm" || magnitude == "m") {
            if (is_number(measure)) {
                //do stuff
                std::cout<<"so true"<<std::endl;
            } else {
                std::cout<<"medida inválida!"<<std::endl;
                return;
            }
        } else {
            std::cout<<"magnitud inválida!"<<std::endl;
            return;
        }
    } else if (type == "girar") {
        if (magnitude == "g") {
            //do stuff
            std::cout<<"true"<<std::endl;
        } else {
            std::cout<<"magnitud inválida!"<<std::endl;
            return;
        }
    } else {
        std::cout<<"tipo de movimiento inválido!"<<std::endl;
        return;
    }
}

void agregar_analisis(std::string type, std::string obj, std::string comment) {
    if (type == "fotografiar" || type == "composicion" || type == "perforar") {
        if (obj == "roca" || obj == "crater" || obj == "monticulo" || obj == "duna") {
            if (comment.front() == '\'' && comment.back() == '\'') {
                // do something
            } else {
                std::cout<<"el comentario debe estar encerrado entre comillas simples!"<<std::endl;
            }
        } else {
            std::cout<<"tipo de análisis inválido!"<<std::endl;
        }
    } else {
        std::cout<<"objeto inválido!"<<std::endl;
    }

    
}

void agregar_elemento(std::string type, std::string size, std::string measure, std::string x, std::string y) {

}

void guardar(std::string type, std::string fileName) {

}

void simular_comandos(std::string x, std::string y) {

}

void ubicar_elementos() {

}

void en_cuadrante(std::string x1, std::string x2, std::string y1, std::string y2) {

}

void crear_mapa(std::string conn_coeficient) {
    
}

void ruta_mas_larga() {

}

void ayuda(std::map<std::string, int> cmd_map, std::string cmd) {
    std::cout<<std::endl<<std::endl;
    switch (cmd_map[cmd]) {
        case 1:
            std::cout<<"Uso: cargar_comandos <nombre_archivo>"<<std::endl;
            break;
        case 2:
            std::cout<<"Uso: cargar_elementos <nombre_archivo>"<<std::endl;
            break;
        case 3:
            std::cout<<"Uso: agregar_movimiento <tipo_mov> <magnitud> <unidad_med>"<<std::endl;
            break;
        case 4:
            std::cout<<"Uso: agregar_analisis <tipo_analisis> <objeto> <comentario>"<<std::endl;
            break;
        case 5:
            std::cout<<"Uso: agregar_elemento <tipo_comp <tamano> <unidad_med> <coordX> <coordY>"<<std::endl;
            break;
        case 6:
            std::cout<<"Uso: guardar <tipo_archivo> <nombre_archivo>"<<std::endl;
            break;
        case 7:
            std::cout<<"Uso: simular_comandos <coordX> <coordY>"<<std::endl;
            break;
        case 8:
            std::cout<<"Uso: salir"<<std::endl;
            break;
        case 9:
            std::cout<<"Uso: ubicar_elementos"<<std::endl;
            break;
        case 10:
            std::cout<<"Uso: en_cuadrante <coordX1> <coordX2> <coordY1> <coordY2>"<<std::endl;
            break;
        case 11:
            std::cout<<"Uso: crear_mapa <coeficiente_conectividad>"<<std::endl;
            break;
        case 12:
            std::cout<<"Uso: ruta_mas_larga"<<std::endl;
            break;
        case 13:
            std::cout<<"Uso: ayuda <comando>"<<std::endl;
            break;
        default:
            std::cout<<"Comando no encontrado! Intente nuevamente. Uso: ayuda <comando>"<<std::endl;
            break;
    }
}