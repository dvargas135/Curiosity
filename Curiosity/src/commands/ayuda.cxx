#include "ayuda.hpp"

#include <iostream>
#include <map>
#include <string>

void ayuda(std::map<std::string, int> cmd_map, std::string cmd) {
    switch (cmd_map[cmd]) {
        case 1:
            printf("Uso: cargar_comandos <nombre_archivo>\n");
            break;
        case 2:
            printf("Uso: cargar_elementos <nombre_archivo>\n");
            break;
        case 3:
            printf("Uso: agregar_movimiento <tipo_mov> <magnitud> <unidad_med>\n");
            break;
        case 4:
            printf("Uso: agregar_analisis <tipo_analisis> <objeto> <comentario>\n");
            break;
        case 5:
            printf("Uso: agregar_elemento <tipo_comp <tamano> <unidad_med> <coordX> <coordY>\n");
            break;
        case 6:
            printf("Uso: guardar <tipo_archivo> <nombre_archivo>\n");
            break;
        case 7:
            printf("Uso: simular_comandos <coordX> <coordY>\n");
            break;
        case 8:
            printf("Uso: salir\n");
            break;
        case 9:
            printf("Uso: ubicar_elementos\n");
            break;
        case 10:
            printf("Uso: en_cuadrante <coordX1> <coordX2> <coordY1> <coordY2>\n");
            break;
        case 11:
            printf("Uso: crear_mapa <coeficiente_conectividad>\n");
            break;
        case 12:
            printf("Uso: ruta_mas_larga\n");
            break;
        case 13:
            printf("Uso: ayuda <comando>\n");
            break;
        default:
            printf("Comando no encontrado! Intente nuevamente. Uso: ayuda <comando>\n");
            break;
    }
}