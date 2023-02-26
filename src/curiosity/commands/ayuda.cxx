#include "ayuda.h"

#include <iostream>
#include <map>
#include <string>

void ayuda(std::map<std::string, int> cmd_map, std::string cmd) {
    std::cout<<std::endl<<std::endl;
    switch (cmd_map[cmd]) {
        case 1:
            std::cout << "Uso: cargar_comandos <nombre_archivo>" << std::endl;
            break;
        case 2:
            std::cout << "Uso: cargar_elementos <nombre_archivo>" << std::endl;
            break;
        case 3:
            std::cout << "Uso: agregar_movimiento <tipo_mov> <magnitud> <unidad_med>" << std::endl;
            break;
        case 4:
            std::cout << "Uso: agregar_analisis <tipo_analisis> <objeto> <comentario>" << std::endl;
            break;
        case 5:
            std::cout << "Uso: agregar_elemento <tipo_comp <tamano> <unidad_med> <coordX> <coordY>" << std::endl;
            break;
        case 6:
            std::cout << "Uso: guardar <tipo_archivo> <nombre_archivo>" << std::endl;
            break;
        case 7:
            std::cout << "Uso: simular_comandos <coordX> <coordY>" << std::endl;
            break;
        case 8:
            std::cout << "Uso: salir" << std::endl;
            break;
        case 9:
            std::cout << "Uso: ubicar_elementos" << std::endl;
            break;
        case 10:
            std::cout << "Uso: en_cuadrante <coordX1> <coordX2> <coordY1> <coordY2>" << std::endl;
            break;
        case 11:
            std::cout << "Uso: crear_mapa <coeficiente_conectividad>" << std::endl;
            break;
        case 12:
            std::cout << "Uso: ruta_mas_larga" << std::endl;
            break;
        case 13:
            std::cout << "Uso: ayuda <comando>" << std::endl;
            break;
        default:
            std::cout << "Comando no encontrado! Intente nuevamente. Uso: ayuda <comando>" << std::endl;
            break;
    }
}